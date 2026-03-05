#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=200+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn],b[maxn];
int dp[maxn][maxn][2];

void solve(){
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            dp[i][j][0]=min(dp[i+1][j][0]+(a[i+1]-a[i])*(b[i]+b[n]-b[j]),dp[i+1][j][1]+(a[j]-a[i])*(b[i]+b[n]-b[j]));
            dp[i][j][1]=min(dp[i][j-1][0]+(a[j]-a[i])*(b[i-1]+b[n]-b[j-1]),dp[i][j-1][1]+(a[j]-a[j-1])*(b[i-1]+b[n]-b[j-1]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1]);
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i]>>b[i],b[i]+=b[i-1];
    memset(dp,0x3f,sizeof(dp));
    dp[m][m][0]=dp[m][m][1]=0;
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