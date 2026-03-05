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
const ll maxn=1e3+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
ll mp[maxn][maxn],a[maxn],b[maxn];
ll dp[2][2];


ll Cal(){
    dp[0][1]=a[1],dp[0][0]=0;
    int now=1;
    for(int i=2;i<=n;++i){
        bool ze=0,ne=0,po=0;
        dp[now][0]=dp[now][1]=INF;
        for(int j=1;j<=n;++j){
            int k=mp[i][j]-mp[i-1][j];
            ze|=k==0,ne|=k==-1,po|=k==1;
        }
        if(!ze) {
            dp[now][0]=min(dp[now][0],dp[now^1][0]);
            dp[now][1]=min(dp[now][1],dp[now^1][1]+a[i]);
        }if(!ne){
            dp[now][1]=min(dp[now][1],dp[now^1][0]+a[i]);
        }if(!po){
            dp[now][0]=min(dp[now][0],dp[now^1][1]);
        }
        now^=1;
    }now^=1;
    return min(dp[now][0],dp[now][1]);
}

void solve(){
    // cout<<Cal()<<endl;
    ll ans=Cal();
    for(int i=1;i<=n;++i) 
        for(int j=i+1;j<=n;++j) 
            swap(mp[i][j],mp[j][i]);
    swap(a,b);
    // cout<<Cal()<<endl;
    ans+=Cal();
    cout<<(ans>=INF?-1:ans)<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>mp[i][j];
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];
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