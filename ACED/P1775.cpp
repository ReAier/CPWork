#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
int dp[maxn][maxn],sum[maxn];

void solve(){
    for(int l=1;l<n;++l) for(int i=1;i+l<=n;++i) for(int k=i;k<i+l;++k){
        int j=i+l;
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
        // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
    // for(int l=0;l<n;++l) {for(int i=1;i+l<=n;++i) cout<<dp[i][i+l]<<" ";cout<<endl;}
    cout<<dp[1][n];
}

void init(){
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;++i) 
        cin>>a[i],sum[i]=sum[i-1]+a[i],dp[i][i]=0;
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