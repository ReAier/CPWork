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
const ll maxn=1e6+10,INF=0x3f3f3f3f,mod=998244353;
const double eps=1e-8,Pi=acos(-1);
ll n,m;
ll a[maxn],id[maxn],pre[maxn];
vector<int>pos[maxn];
ll dp[maxn],sum1[maxn],sum2[maxn];

void solve(){
    for(int i=1;i<=n;++i){
        if(id[i]>=a[i]){
            int las=pos[a[i]][id[i]-a[i]];
            dp[i]=(((sum1[las-1]-sum2[pre[i]]+1-sum2[pre[las]])%mod)+mod)%mod;
        }
        sum1[i]=(dp[i]+sum1[i-1])%mod;
        sum2[i]=(dp[i]+sum2[pre[i]])%mod;
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
        ans=(ans+dp[i])%mod;
    cout<<ans%mod<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pre[i]=pos[a[i]].size()?pos[a[i]].back():0;
        pos[a[i]].push_back(i);
        id[i]=pos[a[i]].size();
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