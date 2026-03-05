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
vector<int>e[maxn];
int dp[maxn][2];
int d[maxn];


void dfs(int u){
    for(int v:e[u]){
        dfs(v);
        dp[u][0]+=max(dp[v][1],dp[v][0]);
        dp[u][1]+=dp[v][0];
    }
}

void solve(){
    int ans;
    for(int i=1;i<=n;++i) if(!d[i]) 
        dfs(i),ans=max(dp[i][0],dp[i][1]);
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>dp[i][1];
    int u,v;
    for(int i=1;i<n;++i) cin>>u>>v,e[v].push_back(u),d[u]++;
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