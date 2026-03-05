#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e4+10,INF=1e9+10,mod=998244353;
int n,m;
int dp[maxn][maxn];
int x,y;

void solve(){
    dp[abs(x-y)][0]=1;
    for(int i=0;i<=m;++i){
        for(int j=1;j<n;++j){
            if(j>(n/2)){
                dp[j][i+1]=(dp[j][i+1]+dp[j][i])%mod;
                if(j+1<n)
                dp[j+1][i+1]=(dp[j+1][i+1]+dp[j][i])%mod;
                if(j+2<n)
                dp[j+2][i+1]=(dp[j+2][i+1]+dp[j][i])%mod;
            }else{
                dp[j][i+1]=(dp[j][i+1]+dp[j][i])%mod;
                if(j-1>0)
                dp[j-1][i+1]=(dp[j-1][i+1]+dp[j][i])%mod;
                if(j-2>0)
                dp[j-2][i+1]=(dp[j-2][i+1]+dp[j][i])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<n;++i) ans=(ans+dp[i][m])%mod;
    cout<<ans;
}

void init(){
    cin>>n>>x>>y>>m;
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