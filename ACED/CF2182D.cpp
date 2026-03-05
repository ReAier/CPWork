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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=998244353;
const double eps=1e-8,Pi=acos(-1);
int n=50,m,k;
ll a[maxn],fac[maxn],inv[maxn];
inline ll fastpow(ll a,ll x){
    ll ans=1;
    while(x){
        if(x&1) ans=ans*a%mod;
        a=a*a%mod;
        x>>=1;
    }return ans;
}
inline ll C(int x,int y){
    return ((fac[x]*inv[y])%mod)*inv[x-y]%mod;
}

void solve(){
    for(int i=1;i<=m;++i){
        k-=a[n]-a[i]-1;
        a[i]=a[n]-1;
    }
    if(k<0) 
        cout<<"0\n";
    else if(k<=m){
        cout<<(C(m,k)*fac[n-m+k]%mod)*fac[m-k]%mod<<'\n';
    }else {
        k-=m;
        k%=n;
        cout<<(C(n,k)*fac[n-k]%mod)*fac[k]%mod<<'\n';
    }
}
void init(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) 
        cin>>a[i];
    sort(a+1,a+1+n);
    m=n;
    while(a[m]==a[n]&&m>0) 
        --m;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    fac[0]=inv[0]=1;
    for(int i=1;i<=n;++i)
        fac[i]=fac[i-1]*i%mod;
    inv[n]=fastpow(fac[n],mod-2);
    for(int i=n-1;i>=1;--i)
        inv[i]=inv[i+1]*(i+1)%mod;
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