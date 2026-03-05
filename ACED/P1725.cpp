#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
// #define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
int L,R;
int a[maxn],dp[maxn];
deque<int>q;

void solve(){
    for(int i=1;i<=n+R;++i) dp[i]=-INF;
    for(int i=L;i<=n+R;++i){
        while(q.size()&&dp[q.front()]<=dp[i-L]) q.pop_front();
        while(q.size()&&q.back()<i-R) q.pop_back();
        q.push_front(i-L);
        dp[i]=dp[q.back()]+a[i];
    }

    // for(int i=L;i<=n+R;++i) 
    //     for(int j=max(0,i-R);j<=i-L;++j) 
    //         dp[i]=max(dp[j]+a[i],dp[i]); 
    
    int ans=-INF;
    for(int i=n+1;i<=n+R;++i) ans=max(ans,dp[i]);
    cout<<ans;
}

void init(){
    cin>>n>>L>>R;
    for(int i=0;i<=n;++i) cin>>a[i];
    // for(int i=1;i<L;++i) a[i]=0;
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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