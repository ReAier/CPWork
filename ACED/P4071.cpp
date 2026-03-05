#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n=1e6,m;
ll fac[maxn],invfac[maxn],inv[maxn],dfac[maxn];

ll C(int a,int b){
    return (((fac[a]*invfac[b])%mod)*invfac[a-b])%mod;
}

void solve(){
    while(m--){
        ll a,b;
        cin>>a>>b;
        cout<<(C(a,b)*dfac[a-b])%mod<<endl;
    }
}

void init(){
    cin>>m;
    invfac[0]=fac[0]=fac[1]=1;
    inv[1]=invfac[1]=1;
    dfac[0]=1,dfac[1]=0;
    for(int i=2;i<=n;++i) 
        fac[i]=(fac[i-1]*i)%mod,inv[i]=((mod-mod/i)*inv[mod%i])%mod,invfac[i]=(invfac[i-1]*inv[i])%mod;
    for(int i=2;i<=n;++i) 
        dfac[i]=((i-1)*(dfac[i-1]+dfac[i-2]))%mod;
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