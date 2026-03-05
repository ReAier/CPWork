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
int n,m;
ll frac[maxn],ifrac[maxn];

ll fastpow(ll a,ll x){
    ll ans=1;
    while(x){
        if(x&1) ans=(ans*a)%mod;
        x>>=1;a=(a*a)%mod;
    }return ans;
}
ll C(ll a,ll b){
    return ((frac[a]*ifrac[b])%mod)*ifrac[a-b]%mod;
}
int Get(int x){
    int ans=0;
    while(x){   
        ans+=1+(x&1);
        x>>=1;
    }return ans-1;
}
void solve(){
    ll ans=0;
    for(int i=1;i<=n;++i){
        for(int j=max(m-i+1,0);j<i;++j){
            ans+=C(i-1,j);
        }
    }
    cout<<ans+(Get(1ll<<n)>m)<<'\n';
}
void init(){
    cin>>n>>m;
    n=log2(n);
    ifrac[0]=frac[0]=1;
    for(int i=1;i<=40;++i){
        frac[i]=(frac[i-1]*i)%mod;
        ifrac[i]=fastpow(frac[i],mod-2);
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