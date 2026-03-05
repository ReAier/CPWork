#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int l[maxn],r[maxn],tag[maxn];
bool ans[maxn];
struct Dsu{
    int fa[maxn],siz[maxn];
    stack<pii>s;
    int Find(int u){
        while(fa[u]!=u) u=fa[u];
        return u;
    }
    void Merge(int u,int v){
        u=Find(u),v=Find(v);
        if(u==v) return s.push({0,0});
        if(siz[u]<siz[v]) swap(u,v);
        s.push({v,siz[v]});
        siz[u]+=siz[v];
        tag[v]-=tag[u];
        fa[v]=u;
    }
    void Undo(int k){
        while(k--){
            auto[v,sz]=s.top();s.pop();
            tag[v]+=tag[fa[v]];
            siz[fa[v]]-=sz;
            fa[v]=v;
        }
    }
    void Init(){
        for(int i=1;i<=n;++i)   
            fa[i]=i,siz[i]=1;
    }
}d;
struct SegTree{
    struct Node{
        vector<pii>e;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define e(p) t[p].e
    void Add(int p,int l,int r,int L,int R,pii k){
        if(L<=l&&R>=r) return e(p).push_back(k);
        if(L>r||R<l) return;
        int mid=l+r>>1;
        Add(ls(p),l,mid,L,R,k);
        Add(rs(p),mid+1,r,L,R,k);
    }
    void Add(int l,int r,pii k){
        Add(1,1,2e5,l,r,k);
    }
    void Dfs(int p,int l,int r){
        for(auto[u,v]:e(p)) d.Merge(u,v);
        if(l==r) tag[d.Find(1)]++;
        else{
            int mid=l+r>>1;
            Dfs(ls(p),l,mid);
            Dfs(rs(p),mid+1,r);
        }d.Undo(e(p).size());
    }
}t;

void solve(){
    t.Dfs(1,1,2e5);
    for(int i=1;i<=n;++i)
        if(tag[i]) cout<<i<<" ";
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)   
        cin>>l[i]>>r[i];
    d.Init();
    int u,v;
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        if(max(l[u],l[v])<=min(r[u],r[v]))
            t.Add(max(l[u],l[v]),min(r[u],r[v]),{u,v});
    }
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    // ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int T=1;
    // cin>>T;
    // while(cin>>n){
    while(T--){
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}