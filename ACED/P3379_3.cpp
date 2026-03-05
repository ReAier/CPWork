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
int n,m,s;
vector<int>e[maxn];
int fa[maxn],top[maxn],siz[maxn],son[maxn],dep[maxn];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

void dfs1(int u,int fat){
    dep[u]=dep[fat]+1;
    fa[u]=fat;
    siz[u]=1;
    for(int v:e[u]){
        if(v==fat) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) son[u]=v;
    }
}
void dfs2(int u,int to){
    top[u]=to;
    if(!son[u]) return;
    dfs2(son[u],to);
    for(int v:e[u]){
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}

int Lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

void solve(){
    dfs1(s,0);
    dfs2(s,s);
    while(m--){
        int u=read(),v=read();
        printf("%d\n",Lca(u,v));
    }
}

void init(){
    n=read();
    m=read();
    s=read();
    for(int i=1;i<n;++i) {
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
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