#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=2e6+10,INF=1e9+10,mod=1e9+7;
ll n,m,n2;
ll a[100],b[maxn],c[maxn],idx1,idx2;

ll query1(ll x){
    ll ans=0;
    for(ll i=1;i<=n2;++i)
        if(x&(1ll<<(i-1ll))) ans+=a[i];
    return ans;
}

ll query2(ll x){
    ll ans=0;
    for(ll i=1;i<=n-n2;++i)
        if(x&(1ll<<(i-1ll))) ans+=a[i+n2];
    return ans;

}

void solve(){
    n2=n/2;
    ll ans=0;
    for(ll i=0;i<=(1ll<<n2)-1ll;++i) b[++idx1]=query1(i);
    sort(b+1,b+1+idx1);
    for(ll i=0;i<=(1ll<<(n-n2))-1ll;++i) c[++idx2]=query2(i);
    sort(c+1,c+1+idx2);
    ll j=idx2;
    for(ll i=1;i<=idx1;++i){
        while(b[i]+c[j]>m&&j>=1) --j; 
        ans+=j;
    }
    cout<<ans;
}

void init(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
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