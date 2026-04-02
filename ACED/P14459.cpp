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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m;
ll a[maxn];
ll sum=1,dp[maxn][2],flg;

void solve(){
    dp[1][0]=~a[1]?a[1]>=n:max(m-n+1,0ll);
    for(int i=2;i<=n;++i){
        if(a[i]==1||a[i]==-1)
            dp[i][1]=dp[i-1][0];
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod*(a[i]==-1?max(m-n+1,0ll):a[i]>=n)%mod;
    }
    cout<<((sum-dp[n][0]-flg)%mod+mod)%mod<<'\n';
}
void init(){
    cin>>n>>m;
    flg=n&1;
    for(int i=1;i<=n;++i)
        cin>>a[i],sum=sum*(~a[i]?1:m)%mod,flg&=a[i]==1||a[i]==-1;
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