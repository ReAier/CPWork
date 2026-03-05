#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
char s[maxn][maxn];
int dp[maxn][maxn],sum[maxn],suf[maxn];
void GetSF(int i){
    for(int j=1;j<=n;++j)
        sum[j]=sum[j-1]+(s[i][j]=='#');
    for(int j=n;j>=1;--j)
        suf[j]=suf[j+1]+(s[i][j]=='.');
}
void solve(){
    for(int i=1;i<=n;++i){
        GetSF(i);
        for(int j=0;j<=n;++j)   
            dp[i][j]=dp[i-1][j]+sum[j]+suf[j+1];
        for(int j=n-1;j>=0;--j)
            dp[i][j]=min(dp[i][j],dp[i][j+1]);
    }
    cout<<dp[n][0];
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        scanf("%s",s[i]+1);
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