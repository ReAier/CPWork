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
ll n,m,k;

ll fac[maxn],invfac[maxn];
ll Pow(ll a,ll x){
    ll ans=1;
    while(x){
        if(x&1)
            ans=ans*a%mod;
        x>>=1;
        a=a*a%mod;
    }
    return ans;
}
ll C(int a,int b){
    return fac[a]*invfac[b]%mod*invfac[a-b]%mod;
}


void solve(){
    ll ans=0;
    for(int i=1;i<=min(k,n-k+1);++i)
        ans=(ans+C(k-1,i-1)%mod*C(n-k+1,i)%mod*Pow(m,i)%mod*Pow(m-1,k-i))%mod;
    cout<<ans<<'\n';
}
void init(){
    cin>>n>>m>>k;
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
    fac[0]=1;
    for(ll i=1;i<=1e6;++i) 
        fac[i]=fac[i-1]*i%mod;
    invfac[int(1e6)]=Pow(fac[int(1e6)],mod-2);
    for(ll i=1e6;i>=1;--i)
        invfac[i-1]=invfac[i]*i%mod;
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