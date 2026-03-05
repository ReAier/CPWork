#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=10007;
ll n,m;
ll a[maxn];
vector<pair<ll,ll>>c[maxn][2];


ll sumi[maxn],sumn[maxn],sumin[maxn];



void solve(){
    ll ans=0;
    for(int i=1;i<=m;++i){
        for(int j=0;j<=1;++j){
            int idx=0;
            for(auto u:c[i][j]){
                ans=(ans+u.first*sumi[idx]+u.second*sumn[idx]+sumin[idx]+(idx*u.first*u.second))%mod;
                idx++;
                sumi[idx]=(sumi[idx-1]+u.second)%mod;
                sumn[idx]=(sumn[idx-1]+u.first)%mod;
                sumin[idx]=(sumin[idx-1]+u.first*u.second)%mod;
            }
        }
    }
    cout<<ans;
}


void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) {
        int co;
        cin>>co;
        c[co][i&1].push_back({a[i],i});
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