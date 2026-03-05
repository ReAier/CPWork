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

struct Edge{
    int u,v,w,nx;
    Edge(){}
    Edge(int U,int V,int W,int Nx):u(U),v(V),w(W),nx(Nx){}
    bool operator<(const Edge &x)const{return w<x.w;}
}e[maxn];

int fa[maxn];
int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}
void merge(int x,int y){
    fa[findfa(x)]=findfa(y);
}

int kruskal(){
    sort(e+1,e+1+m);
    int tcnt=0,ans=0;
    for(int i=1;i<=m;++i){
        int u=e[i].u,v=e[i].v;
        if(findfa(u)==findfa(v)) continue;
        merge(u,v);
        ans+=e[i].w;
        if(++tcnt==n-1) return ans;
    }
    return -1;
}

void solve(){
    int ans=kruskal();
    if(~ans) printf("%d",ans);
    else printf("orz");
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=m;++i) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=n;++i) fa[i]=i;
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