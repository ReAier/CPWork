#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=4e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct Edge{
    int u,v,w;
    bool operator<(Edge x){
        return w>x.w;
    }
}e[maxn];
int rt[maxn];
int Find(int x){
    return rt[x]==x?x:rt[x]=Find(rt[x]);
}
bool Merge(int u,int v){
    if(Find(u)==Find(v)) 
        return 0;
    rt[Find(u)]=Find(v);
    return 1;
}

void solve(){
    ll ans=0;
    sort(e+1,e+1+m);
    for(int i=1;i<=m;++i) if(Merge(e[i].u,e[i].v)) 
        ans+=e[i].w;
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j)
        e[++m]={i,j,a[i]^a[j]};
    for(int i=1;i<=n;++i) 
        rt[i]=i;
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