#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=200+10,INF=1e9+10,mod=1e9+7;
int n,m;
ll e[maxn][maxn],d[maxn][maxn];



void solve(){
    ll ans=INF;
    for(int k=1;k<=n;++k){
        for(int i=1;i<k;++i){
            for(int j=i+1;j<k;++j){
                ans=min(ans,d[i][j]+e[k][i]+e[k][j]);
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    if(ans==INF)
        cout<<"No solution.";
    else cout<<ans;
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i!=j) e[i][j]=INF;
    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        e[u][v]=min(e[u][v],w);
        e[v][u]=min(e[v][u],w);
    }
    memcpy(d,e,sizeof(e));
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