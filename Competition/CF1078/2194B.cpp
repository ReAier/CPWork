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
ll n,m,x,y,sum;
ll a[maxn];

void solve(){
    ll ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,a[i]+sum-((a[i]/x)*y));
    cout<<ans<<'\n';
}
void init(){
    cin>>n>>x>>y;
    sum=0;
    for(int i=1;i<=n;++i)
        cin>>a[i],sum+=(a[i]/x)*y;
    sort(a+1,a+1+n,[](ll x1,ll x2){
        return (x1%x)==(x2%x)?(x1>x2):(x1%x)>(x2%x);
    });
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