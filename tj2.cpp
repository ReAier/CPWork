#include<bits/stdc++.h>
using namespace std;
namespace fast_IO{
#define ld cin
#define jyt cout
} using namespace fast_IO;
#define ll long long
#define ull unsigned long long
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)
#define bitcount(x) __builtin_popcount(x)
#define albit(x) ((1 << (x)) - 1)
#define mkbit(x) (1 << (x - 1))
#define gtbit(x, id) (((x) >> (id - 1)) & 1)
// #define ld cin
// #define jyt cout
// #define int long long
const int N = 2e6 + 7;
const int inf = 1e9 + 7;
namespace TopTree {
    struct Mat {ll o[2][2]; Mat() {memset(o, 0, sizeof(o));}};
    int a[N], fa[N], sz[N], son[N], dep[N], Cluster[N];
    vector<int> G[N];
    struct Data {int sz; Mat lxl; Data() {sz = 0, lxl = Mat();}}; // 维护的信息
    struct Node {
        int lc, rc, fa; char op; Data v;
#define ls(x) tr[x].lc
#define rs(x) tr[x].rc
#define fa(x) tr[x].fa
    } tr[N]; int Trc = 0;  
    inline Data Compess(Data &a, Data &b) {
        Data c;
        c.sz = a.sz + b.sz;
        c.lxl.o[0][0] = max(b.lxl.o[0][0] + a.lxl.o[0][0], b.lxl.o[0][1] + a.lxl.o[1][0]);
        c.lxl.o[1][0] = max(b.lxl.o[1][0] + a.lxl.o[0][0], b.lxl.o[1][1] + a.lxl.o[1][0]);
        c.lxl.o[0][1] = max(b.lxl.o[0][0] + a.lxl.o[0][1], b.lxl.o[0][1] + a.lxl.o[1][1]);
        c.lxl.o[1][1] = max(b.lxl.o[1][0] + a.lxl.o[0][1], b.lxl.o[1][1] + a.lxl.o[1][1]);
        return c;
    }
    inline Data Rake(Data &a, Data &b) {
        Data c;
        c.sz = a.sz + b.sz;
        c.lxl.o[0][0] = a.lxl.o[0][0] + max(b.lxl.o[0][0], b.lxl.o[1][0]);
        c.lxl.o[1][0] = a.lxl.o[1][0] + max(b.lxl.o[0][0], b.lxl.o[1][0]);
        c.lxl.o[0][1] = a.lxl.o[0][1] + max(b.lxl.o[0][1], b.lxl.o[1][1]);
        c.lxl.o[1][1] = a.lxl.o[1][1] + max(b.lxl.o[0][1], b.lxl.o[1][1]);
        return c;
    }
    inline Data init(int w) { // 初始化一个边权为 w 的基簇
        Data c; 
        c.sz = 1;
        c.lxl.o[0][0] = 0, c.lxl.o[0][1] = 0, c.lxl.o[1][0] = w, c.lxl.o[1][1] = -inf;
        return c;
    }
    inline int BaseCluster(int w) {return ++Trc, tr[Trc].op = 'B', tr[Trc].v = init(w), Trc;} // 创建一个基簇
    inline void pushup(int x) {
        tr[x].v = (tr[x].op == 'R' ? Rake : Compess)(tr[ls(x)].v, tr[rs(x)].v);
    }
    inline int Merge(int x, int y, char op) {
        return ++Trc, fa(tr[Trc].lc = x) = fa(tr[Trc].rc = y) = Trc, tr[Trc].op = op, pushup(Trc), Trc;
    } // 创立一个 op 类型的结点用于合并两个簇 x,y
    inline void Prework(int x, int p) {
        fa[x] = p, sz[x] = 1, dep[x] = dep[p] + 1; 
        for (int v : G[x]) if (v ^ p) 
            Cluster[v] = BaseCluster(a[v]), Prework(v, x), son[x] = (sz[v] > sz[son[x]] ? v : son[x]), sz[x] += sz[v];
    }
    inline int build(vector<int> &node, int l, int r, char op) { // 分治的用 op 操作把 node 中的簇合成一个。
        if (l == r) return node[l];
        int mid = r - 1, psz = 0, allsz = 0;
        REP(i, l, r) allsz += tr[node[i]].v.sz;
        REP(i, l, r - 1) if ((psz += tr[node[i]].v.sz) * 2 >= allsz) {mid = i; break;}
        return Merge(build(node, l, mid, op), build(node, mid + 1, r, op), op);
    }
    inline int Build(int x) {
        vector<int> compess;
        if (Cluster[x]) compess.emplace_back(Cluster[x]);
        for (; son[x]; x = son[x]) {
            vector<int> rake;
            for (int v : G[x]) if (v ^ fa[x] && v ^ son[x]) 
                rake.emplace_back(Build(v));
            if (!rake.size()) 
                compess.emplace_back(Cluster[son[x]]);
            else compess.emplace_back(Merge(Cluster[son[x]], build(rake, 0, (int)rake.size() - 1, 'R'), 'R')); // 把合并完的轻儿子合到 (x,son[x]) 这条重边上
        }
        return build(compess, 0, (int)compess.size() - 1, 'C');
    }
    inline void Modify(int x, int y) { // 如你所见，修改非常简单。
        tr[Cluster[x]].v = init(a[x] = y);
        for (x = tr[Cluster[x]].fa; x; x = tr[x].fa) pushup(x);
    }
}
namespace JoKing {
    int n, q, TopRt = 0;
    signed main() { int u, v, LA = 0;
        ld >> n >> q, TopTree::G[n + 1].emplace_back(1), TopTree::G[1].emplace_back(n + 1);  
        REP(i, 1, n) ld >> TopTree::a[i];
        REP(i, 2, n) ld >> u >> v, TopTree::G[u].emplace_back(v), TopTree::G[v].emplace_back(u);
        TopTree::Prework(n + 1, 0), TopRt = TopTree::Build(n + 1);
        REP(i, 1, q) ld >> u >> v, TopTree::Modify(u ^= LA, v), jyt << (LA = max(TopTree::tr[TopRt].v.lxl.o[0][0], TopTree::tr[TopRt].v.lxl.o[1][0])) << '\n';
        return 0; 
    }
}
signed main() {
#ifndef WYY
//	freopen("std.in", "r", stdin);
//	freopen("user.out", "w", stdout);
#endif
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    JoKing::main(); return 0;
}
