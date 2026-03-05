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
int e[200][200],e2[200][200];



void solve(){
    for(int k=1;k<=n;++k) 
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j) 
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
    ll ans=INF;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
        memcpy(e2,e,sizeof(e));
        ll res=0;
        for(int k=1;k<=n;++k) for(int l=1;l<=n;++l)
            e2[k][l]=min(e2[k][l],min(e2[k][i]+e2[j][l],e2[k][j]+e2[i][l]));
        for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) res+=e2[i][j];
        ans=min(ans,res);
    }
    cout<<ans;
}

void init(){
    cin>>n>>m;
    memset(e,0x3f,sizeof(e));
    int u,v,w;
    for(int i=1;i<=n;++i) e[i][i]=0;
    for(int i=1;i<=m;++i)cin>>u>>v>>w,e[u][v]=w,e[v][u]=w;
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