#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=500+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
vector<int>e[maxn];
int dp[maxn][maxn];


void Dfs(int u){
    for(int v:e[u]){
        Dfs(v);
        for(int i=m;i>=2;--i) for(int j=i-1;j>=1;--j)
            dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
    }
    // cout<<u<<endl;
    // for(int i=1;i<=m;++i) cout<<dp[u][i]<<" ";
    // cout<<endl;
}

void solve(){
    Dfs(0);
    cout<<dp[0][m];
}

void init(){
    cin>>n>>m;
    ++m;
    int u;
    for(int i=1;i<=n;++i){
        cin>>u>>dp[i][1];
        e[u].push_back(i);
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