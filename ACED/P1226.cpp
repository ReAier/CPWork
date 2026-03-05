#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10;
ll mod;
ll n,m;

ll fastpow(ll a,ll x){
    ll ans=1;
    while(x){
        if(x&1) ans=(ans*a)%mod;
        a*=a;
        a%=mod;
        x>>=1;
    }
    return ans;
}

void solve(){
    printf("%d^%d mod %d=%d",n,m,mod,fastpow(n,m));
}

void init(){
    cin>>n>>m>>mod;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
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