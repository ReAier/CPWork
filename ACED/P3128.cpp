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

int dfn[maxn],idx,son[maxn],siz[maxn],dep[maxn],top[maxn],fa[maxn],id[maxn],idx2;

int w[maxn];

void dfs1(int u,int fat){
    dep[u]=dep[fa[u]=fat]+1;
    dfn[u]=++idx;
    siz[u]=1;
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
    for(int v:e[u]) if(v!=son[u]&&v!=fa[u]) dfs2(v,v);
}

void change(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        w[id[top[u]]]++;
        w[id[u]+1]--;
        u=fa[top[u]];
    }
    if(id[u]>id[v]) swap(u,v);
    w[id[u]]++;
    w[id[v]+1]--;
}

void solve(){
    int u,v,ans=0;
    while(m--){
        cin>>u>>v;
        change(u,v);
    }
    // for(int i=1;i<=n;++i) cout<<w[i]<<endl;
    for(int i=1;i<=n;++i) w[i]+=w[i-1],ans=max(ans,w[i]);
    cout<<ans;
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