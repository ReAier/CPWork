#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e6 + 7;
const long long INF = 1e18; // 使用更大的无穷大，避免相加溢出

namespace TopTree {
    
    // ---------------- 1. 核心数据结构 ----------------
    struct Matrix {
        long long m[2][2];
        Matrix() {
            // 默认初始化为 0
            m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
        }
    };

    struct Data {
        int sz;       // 簇的大小（用于带权中点分治，保证树高）
        Matrix mat;   // 维护的转移矩阵
        Data() : sz(0) {}
    };

    struct Node {
        int lc, rc, fa;
        char op;      // 'B' (Base/基簇), 'C' (Compress/重链压缩), 'R' (Rake/轻儿子合并)
        Data v;
    };

    // 全局变量区
    int val[N], fa_orig[N], sz_orig[N], son[N], dep[N], base_cluster[N];
    vector<int> adj[N];
    Node tr[N]; 
    int node_cnt = 0;

    // ---------------- 2. 矩阵运算与代数转移 ----------------

    // Compress (串联)：将两条相邻的重链片段连接。本质是 Max-Plus 矩阵乘法
    inline Data compress(const Data& a, const Data& b) {
        Data c;
        c.sz = a.sz + b.sz;
        c.mat.m[0][0] = max(b.mat.m[0][0] + a.mat.m[0][0], b.mat.m[0][1] + a.mat.m[1][0]);
        c.mat.m[1][0] = max(b.mat.m[1][0] + a.mat.m[0][0], b.mat.m[1][1] + a.mat.m[1][0]);
        c.mat.m[0][1] = max(b.mat.m[0][0] + a.mat.m[0][1], b.mat.m[0][1] + a.mat.m[1][1]);
        c.mat.m[1][1] = max(b.mat.m[1][0] + a.mat.m[0][1], b.mat.m[1][1] + a.mat.m[1][1]);
        return c;
    }

    // Rake (并联)：将轻儿子 (b) 的信息吸收到重链上的点 (a) 中。本质是矩阵加法
    inline Data rake(const Data& a, const Data& b) {
        Data c;
        c.sz = a.sz + b.sz;
        // 注意：a 是重边/点，b 是轻儿子树
        long long b_max_0 = max(b.mat.m[0][0], b.mat.m[1][0]); // 轻儿子不强制限制
        long long b_max_1 = max(b.mat.m[0][1], b.mat.m[1][1]); // 对应的另一列状态
        
        c.mat.m[0][0] = a.mat.m[0][0] + b_max_0;
        c.mat.m[1][0] = a.mat.m[1][0] + b_max_0;
        c.mat.m[0][1] = a.mat.m[0][1] + b_max_1;
        c.mat.m[1][1] = a.mat.m[1][1] + b_max_1;
        return c;
    }

    // 初始化一个原树节点的基簇 (Base Cluster)
    inline Data init_base(int weight) {
        Data c; 
        c.sz = 1;
        c.mat.m[0][0] = 0; c.mat.m[0][1] = 0;
        c.mat.m[1][0] = weight; c.mat.m[1][1] = -INF;
        return c;
    }

    // ---------------- 3. 树结构维护 ----------------

    // 向上更新节点信息
    inline void pushup(int x) {
        if (tr[x].op == 'R') {
            tr[x].v = rake(tr[tr[x].lc].v, tr[tr[x].rc].v);
        } else if (tr[x].op == 'C') {
            tr[x].v = compress(tr[tr[x].lc].v, tr[tr[x].rc].v);
        }
    }

    // 创建新簇：合并 x 和 y
    inline int merge_clusters(int x, int y, char op) {
        int u = ++node_cnt;
        tr[u].lc = x; tr[u].rc = y; tr[u].op = op;
        tr[x].fa = tr[y].fa = u;
        pushup(u);
        return u;
    }

    // ---------------- 4. 树剖与 Top Tree 构建 ----------------

    // 第一遍 DFS：树链剖分基础信息
    void prework(int u, int p) {
        fa_orig[u] = p;
        sz_orig[u] = 1;
        dep[u] = dep[p] + 1; 
        
        // 为原树的每个节点创建一个 Base 节点
        base_cluster[u] = ++node_cnt;
        tr[base_cluster[u]].op = 'B';
        tr[base_cluster[u]].v = init_base(val[u]);

        for (int v : adj[u]) {
            if (v != p) {
                prework(v, u);
                if (sz_orig[v] > sz_orig[son[u]]) {
                    son[u] = v;
                }
                sz_orig[u] += sz_orig[v];
            }
        }
    }

    // 带权中点分治核心：保证生成的 Top Tree 高度严格 O(log N)
    int build_balanced_tree(vector<int>& nodes, int l, int r, char op) {
        if (l == r) return nodes[l];
        
        int mid = r - 1;
        long long total_sz = 0, current_sz = 0;
        
        for (int i = l; i <= r; ++i) total_sz += tr[nodes[i]].v.sz;
        
        for (int i = l; i < r; ++i) {
            current_sz += tr[nodes[i]].v.sz;
            if (current_sz * 2 >= total_sz) { // 找到带权中点
                mid = i; 
                break;
            }
        }
        return merge_clusters(
            build_balanced_tree(nodes, l, mid, op), 
            build_balanced_tree(nodes, mid + 1, r, op), 
            op
        );
    }

    // 递归构建 Top Tree
    int build_toptree(int root) {
        vector<int> chain_nodes; // 存放重链上的节点
        
        if (base_cluster[root]) chain_nodes.push_back(base_cluster[root]);
        
        for (int curr = root; son[curr]; curr = son[curr]) {
            vector<int> light_children;
            
            // 收集所有轻儿子的 Top Tree 根
            for (int v : adj[curr]) {
                if (v != fa_orig[curr] && v != son[curr]) {
                    light_children.push_back(build_toptree(v));
                }
            }
            
            // 关键：将当前点的重儿子，与“合并后的所有轻儿子”进行 Rake
            if (light_children.empty()) {
                chain_nodes.push_back(base_cluster[son[curr]]);
            } else {
                int rake_root = build_balanced_tree(light_children, 0, light_children.size() - 1, 'R');
                chain_nodes.push_back(merge_clusters(base_cluster[son[curr]], rake_root, 'R'));
            }
        }
        
        // 最后将整条重链进行 Compress 合并
        return build_balanced_tree(chain_nodes, 0, chain_nodes.size() - 1, 'C');
    }

    // ---------------- 5. 动态修改 ----------------
    
    // O(log N) 向上爬树更新
    void modify(int x, int new_val) {
        val[x] = new_val;
        int leaf = base_cluster[x];
        tr[leaf].v = init_base(new_val);
        
        for (int curr = tr[leaf].fa; curr; curr = tr[curr].fa) {
            pushup(curr);
        }
    }
}

// ---------------- 主函数区 ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    // if (!(cin >> n >> q)) return 0;
    cin>>n>>q;

    // 虚根技巧：增加一个超级根 n+1 连接 1，方便处理全局信息的提取
    TopTree::adj[n + 1].push_back(1);
    TopTree::adj[1].push_back(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> TopTree::val[i];
    }
    TopTree::val[n + 1] = 0; // 虚根权值为0

    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        TopTree::adj[u].push_back(v);
        TopTree::adj[v].push_back(u);
    }

    // 1. 树剖预处理
    TopTree::prework(n + 1, 0);
    // 2. 构建静态 Top Tree
    int top_root = TopTree::build_toptree(n + 1);

    // 3. 处理询问 (强制在线)
    long long last_ans = 0;
    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        // u ^= last_ans; // 强制在线解密
        
        TopTree::modify(u, v);
        
        // 全局答案就是虚根所在 Top Tree 矩阵的第一列最大值
        last_ans = max(TopTree::tr[top_root].v.mat.m[0][0], TopTree::tr[top_root].v.mat.m[1][0]);
        cout << last_ans << '\n';
    }

    return 0;
}