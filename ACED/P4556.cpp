#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
const double eps=1e-8;
int n,m;
vector<int>e[maxn];

int fa[maxn],son[maxn],top[maxn],siz[maxn],dep[maxn];
void dfs1(int u,int fat){
    fa[u]=fat;siz[u]=1;dep[u]=dep[fat]+1;
    for(int v:e[u]) if(v!=fat) {
        dfs1(v,u),siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) son[u]=v;
    }
}
void dfs2(int u,int tp){
    top[u]=tp;
    if(!son[u]) return;
    dfs2(son[u],tp);
    for(int v:e[u]) if(v!=son[u]&&v!=fa[u]) dfs2(v,v);
}

int Lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

struct SegTrees{
    struct Node{
        int ls,rs,val,maxid,maxval;
    }t[maxn<<3];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define val(p) t[p].val
    #define maxid(p) t[p].maxid
    #define maxval(p) t[p].maxval
    int root[maxn],idx;
    void PushUp(int p){
        if(maxval(ls(p))>=maxval(rs(p))){
            maxval(p)=maxval(ls(p));
            maxid(p)=maxid(ls(p));
        }else{
            maxval(p)=maxval(rs(p));
            maxid(p)=maxid(rs(p));
        }
    }
    void Change(int &p,int l,int r,int x,int k){
        if(!p) p=++idx;
        if(l==r){
            val(p)+=k;
            if(val(p)>0) maxid(p)=l, maxval(p)=val(p);
            else maxid(p)=0,maxval(p)=0;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    void Change(int u,int x,int k){
        Change(root[u],1,1e5,x,k);
    }
    int Merge(int u,int v,int l,int r){
        if(!u||!v) return u|v;
        if(l==r){
            val(u)+=val(v);
            if(val(u)>0) maxid(u)=l, maxval(u)=val(u);
            else maxid(u)=0,maxval(u)=0;
            return u;
        }
        int mid=l+r>>1;
        ls(u)=Merge(ls(u),ls(v),l,mid);
        rs(u)=Merge(rs(u),rs(v),mid+1,r);
        PushUp(u);
        return u;
    }
    void Merge(int u,int v){
        root[u]=Merge(root[u],root[v],1,1e5);
    }
    int Query(int u){
        return maxid(root[u]);
    }
}t;
int ans[maxn];

void dfs3(int u){
    for(int v:e[u]){
        if(v==fa[u]) continue;
        dfs3(v);
        t.Merge(u,v);
    }
    ans[u]=t.Query(u);
}

void solve(){
    int u,v,k,lc;
    while(m--){
        cin>>u>>v>>k;
        lc=Lca(u,v);
        t.Change(u,k,1);
        t.Change(v,k,1);
        t.Change(lc,k,-1);
        if(fa[lc]) t.Change(fa[lc],k,-1);
    }

    dfs3(1);
    for(int i=1;i<=n;++i) cout<<ans[i]<<"\n";
}

void init(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;++i) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    dfs1(1,0);
    dfs2(1,1);
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