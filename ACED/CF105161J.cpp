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
const int maxn=20,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int dp[2][1<<20],a[maxn][maxn];

int GetW(int S,int i){
    return (S>>(i-1))&1;
}

void solve(){
    int MASK=(1<<(m+1))-1,now=0;
    for(int i=0;i<=MASK;++i)
        dp[0][i]=dp[1][i]=-INF;
    dp[1][0]=0;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
        for(int S=0;S<=MASK;++S)
            dp[now][S]=-INF;
        for(int S=0;S<=MASK;++S){
            if(dp[now^1][S]==-INF)
                continue;
            dp[now][(S<<1)&MASK]=max(dp[now][(S<<1)&MASK],dp[now^1][S]);
            if(j==1){
                if(GetW(S,m)+GetW(S,m-1)<=1) 
                    dp[now][(S<<1|1)&MASK]=max(dp[now][(S<<1|1)&MASK],dp[now^1][S]+a[i][j]);
            }else if(j!=m){
                int K=GetW(S,1)+GetW(S,m)+GetW(S,m+1)+GetW(S,m-1);
                if((K<=1)||((K==2)&&(GetW(S,m)==0)&&(GetW(S,m-1)==1))) 
                    dp[now][(S<<1|1)&MASK]=max(dp[now][(S<<1|1)&MASK],dp[now^1][S]+a[i][j]);
            }else{
                if(GetW(S,1)+GetW(S,m)+GetW(S,m+1)<=1)
                    dp[now][(S<<1|1)&MASK]=max(dp[now][(S<<1|1)&MASK],dp[now^1][S]+a[i][j]);
            }
        }
        now^=1;
    }
    int ans=0;
    for(int S=0;S<=MASK;++S)
        ans=max(ans,dp[now^1][S]);
    cout<<ans<<'\n';
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
        cin>>a[i][j];
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