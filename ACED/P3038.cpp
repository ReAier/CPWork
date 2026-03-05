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
int n,m;
vector<int>e[maxn];

struct BitTree{
#define lowbit(x) (x&(-x))
    int t[maxn];
    void change(int x,int k){
        while(x<=n) t[x]+=k,x+=lowbit(x);
    }
    void add(int l,int r){
        change(l,1);
        change(r+1,-1);
    }
    int query(int x){
        int ans=0;
        while(x) ans+=t[x],x-=lowbit(x);
        return ans;
    }
}t;


int dfn[maxn],idx,fa[maxn],son[maxn],dep[maxn],siz[maxn],id[maxn],idx2,top[maxn];
void dfs1(int u,int fat){
    dep[u]=dep[fa[u]=fat]+1;
    siz[u]=1;
    dfn[u]=++idx;
    for(int v:e[u]) if(v!=fat){
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    id[u]=++idx2;
    if(!son[u]) return;
    dfs2(son[u],tp);
    for(int v:e[u]) if(v!=fa[u]&&v!=son[u]) {
        dfs2(v,v);
    }
}

void change(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        t.add(id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if(u==v) return;
    if(id[u]>id[v]) swap(u,v);
    t.add(id[u]+1,id[v]);
}

int query(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    return t.query(id[u]);
}

void solve(){
    char opt;
    int u,v;
    while(m--){
        cin>>opt>>u>>v;
        if(opt=='P'){
            change(u,v);
        }else{
            cout<<query(u,v)<<endl;
        }
    }
    // for(int i=1;i<=n;++i) cout<<id[i]<<" ";
    // cout<<endl;  
    // for(int i=1;i<=n;++i) cout<<t.query(i)<<' '; 
}

void init(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;++i) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
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