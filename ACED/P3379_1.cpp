#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5e5+10,INF=1e9+10,mod=1e9+7;
int n,m,s;
vector<int>e[maxn];

int fa[maxn][21],dep[maxn],lg[maxn];

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

void dfs(int u,int f){
    if(!u) return;
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for(int i=1;i<=lg[dep[u]];++i){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int v:e[u]) if(v!=f) dfs(v,u);
}

int Lca(int u,int v){
    if(dep[v]>dep[u]) swap(u,v);
    for(int i=lg[dep[u]];i>=0;--i) if(dep[fa[u][i]]>=dep[v]) 
        u=fa[u][i];
    if(u==v) return u;
    for(int i=lg[dep[u]];i>=0;--i) if(fa[u][i]!=fa[v][i]) 
        u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}

void solve(){
    dfs(s,0);
    while (m--){
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
    for(int i=1;i<=n;++i) lg[i]=log2(i)+1;
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