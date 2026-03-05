#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int fa[maxn];
bool isen[maxn];
int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
bool Merge(int u,int v){
    int fu=Find(u),fv=Find(v);
    if(isen[fu]&&isen[fv]) return 0;
    fa[fu]=fv;
    if(isen[fu]) isen[fv]=1;
    return 1;
}
struct Edge{
    int u,v,w;
    bool operator<(const Edge &x) const{
        return w>x.w;
    }
}e[maxn];

void solve(){
    ll ans=0;
    for(int i=1;i<n;++i){
        auto [u,v,w]=e[i];
        if(!Merge(u,v)) ans+=w;
    }
    cout<<ans;
}

void init(){
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;++i) cin>>u,isen[u]=1;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<n;++i) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+n);
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