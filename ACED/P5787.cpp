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
const double eps=1e-8;
int n,m,k;
struct Dsu{
    int fa[maxn],siz[maxn];
    stack<pii> s;
    int Find(int x){
        while(x!=fa[x]) 
            x=fa[x];
        return x;
    }
    void Merge(int u,int v){
        u=Find(u),v=Find(v);
        if(u==v) return s.push({0,0});
        if(siz[u]<siz[v]) swap(u,v);
        siz[u]+=siz[v];
        fa[v]=u;
        s.push({v,siz[v]});
    }
    void Undo(int x){
        while(x--){
            auto [v,sz]=s.top();s.pop();
            siz[fa[v]]-=siz[v];
            fa[v]=v;
        }
    }
    void Init(){
        for(int i=1;i<=2*n;++i) 
            fa[i]=i,siz[i]=1;
    }
}s;
bool ans[maxn];
struct SegTree{
    struct Node{
        vector<pii>edg;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define edg(p) t[p].edg
    void Insert(int p,int l,int r,int L,int R,pii e){
        if(L<=l&&R>=r) 
            return edg(p).push_back(e);
        if(l>R||r<L) return;
        int mid=l+r>>1;
        Insert(ls(p),l,mid,L,R,e);
        Insert(rs(p),mid+1,r,L,R,e);
    }
    void Insert(int l,int r,pii e){
        Insert(1,1,k,l,r,e);
    }
    void Dfs(int p,int l,int r){
        bool flg=0;
        for(auto [u,v]:edg(p)){
            if(s.Find(u)==s.Find(v)) 
                flg=1;
            s.Merge(u,v+n);
            s.Merge(u+n,v);
        }if(flg) return s.Undo(edg(p).size()*2);

        if(l!=r){
            int mid=l+r>>1;
            Dfs(ls(p),l,mid);
            Dfs(rs(p),mid+1,r);
        }else ans[l]=1;
        s.Undo(edg(p).size()*2);
    }
}t;

void solve(){
    t.Dfs(1,1,k);
    for(int i=1;i<=k;++i) 
        cout<<(ans[i]?"Yes\n":"No\n");
}
void init(){
    cin>>n>>m>>k;
    int u,v,l,r;
    while(m--){
        cin>>u>>v>>l>>r;
        t.Insert(l+1,r,{u,v});
    }
    s.Init();
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