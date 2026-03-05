#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Dsu{
    int fa[maxn],siz[maxn];
    stack<pair<int,int>>s;
    void Init(){
        for(int i=1;i<=n;++i)
            fa[i]=i,siz[i]=1;
    }
    int Find(int x){
        while(x!=fa[x]) x=fa[x];
        return x;
    }
    void Merge(int u,int v){
        u=Find(u),v=Find(v);
        if(u==v) return s.push({0,0});
        if(siz[u]<siz[v]) swap(u,v);
        fa[v]=u;
        siz[u]+=siz[v];
        s.push({v,siz[v]});
    }
    void Undo(int k){
        while(k--){
            auto [v,sz]=s.top();s.pop();
            int u=fa[v];
            siz[u]-=sz;
            fa[v]=v;
        }
    }
}s;

pair<int,int>Qu[maxn];
int ans[maxn];

struct SegTree{
    struct Node{
        vector<pair<int,int>>edg;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define edg(p) t[p].edg
    void Insert(int p,int l,int r,int L,int R,pair<int,int> k){
        if(L<=l&&R>=r) 
            return edg(p).push_back(k),void();
        if(l>R||r<L) return;
        int mid=l+r>>1;
        Insert(ls(p),l,mid,L,R,k);
        Insert(rs(p),mid+1,r,L,R,k);
    }
    void Dfs(int p,int l,int r){
        for(auto [u,v]:edg(p))
            s.Merge(u,v);
        if(l==r){
            auto [u,v]=Qu[l];
            if(u&&v) ans[l]=s.Find(u)==s.Find(v);
            else ans[l]=-1;
        }else{
            int mid=l+r>>1;
            Dfs(ls(p),l,mid);
            Dfs(rs(p),mid+1,r);
        }s.Undo(edg(p).size());
    }
    void Insert(int l,int r,pair<int,int>k){
        Insert(1,1,m,l,r,k);
    }
}t;

void solve(){
    t.Dfs(1,1,m);
    for(int i=1;i<=m;++i) if(~ans[i]){
        cout<<(ans[i]?'Y':'N')<<'\n';
    }
}
map<pair<int,int>,int>mp;
void init(){
    cin>>n>>m;
    int op,u,v;
    for(int i=1;i<=m;++i){
        cin>>op>>u>>v;
        if(u>v) swap(u,v);
        if(op==1) {
            t.Insert(mp[{u,v}],i-1,{u,v});
            mp.erase({u,v});
        }else if(!op){
            mp[{u,v}]=i;
        }else Qu[i]={u,v};
    }
    for(auto [e,l]:mp)
        t.Insert(l,m,e);
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

