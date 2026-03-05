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
int n,m,sx,sy,tx,ty;
map<int,pii>mp;
ll A[maxn],dp[2][2];

void solve(){
    int lasL=sy,lasR=sy,now=1;
    for(auto [x,k]:mp){
        auto [l,r]=k;
        int len=r-l;
        dp[now][0]=min(dp[now^1][0]+abs(lasL-r),dp[now^1][1]+abs(lasR-r))+len;
        dp[now][1]=min(dp[now^1][0]+abs(lasL-l),dp[now^1][1]+abs(lasR-l))+len;
        // cout<<"L: "<<dp[now][0]<<" R: "<<dp[now][1]<<endl;
        lasL=l,lasR=r;
        now^=1;
    }now^=1;
    cout<<min(dp[now][0],dp[now][1])+tx-sx<<'\n';
}
void init(){
    cin>>n>>sx>>sy>>tx>>ty;
    dp[0][0]=dp[0][1]=0,dp[1][0]=dp[1][1]=INF;
    mp.clear();
    for(int i=1;i<=n;++i)
        cin>>A[i],mp[A[i]]={INF,-INF};
    mp[sx]={sy,sy};
    mp[tx]={ty,ty};
    int B;
    for(int i=1;i<=n;++i){
        cin>>B;
        mp[A[i]].first=min(mp[A[i]].first,B);
        mp[A[i]].second=max(mp[A[i]].second,B);
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
    cin>>T;
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