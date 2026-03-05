#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int dp[maxn][2];
int L[maxn],R[maxn];


void solve(){
    for(int i=2;i<=n;++i){
        dp[i][0]=min(dp[i-1][0]+abs(R[i]-L[i-1]),dp[i-1][1]+abs(R[i]-R[i-1]))+R[i]-L[i]+1;
        dp[i][1]=min(dp[i-1][0]+abs(L[i]-L[i-1]),dp[i-1][1]+abs(L[i]-R[i-1]))+R[i]-L[i]+1;
    }
    cout<<min(dp[n][0]+n-L[n],dp[n][1]+n-R[n]);
}

void init(){
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;++i) cin>>L[i]>>R[i];
    dp[1][0]=2*R[1]-L[1]-1;
    dp[1][1]=R[1]-1;
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