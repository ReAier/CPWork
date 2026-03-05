#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
ll c[maxn],v[maxn],f[maxn];
vector<int>ve[maxn];
ll h[maxn];
unordered_map<ll,int>mp;
mt19937_64 mt;

void solve(){
    ll ans=INF;
    for(int r=1;r<=n;++r){
        if(mp.count(h[r])){
            ll l=mp[h[r]]+1,sum=0;
            for(int i=l;i<=r;++i)
                sum+=v[i]*f[i-l+1];
            ans=min(ans,sum);
        }
        mp[h[r]]=r;
    }
    cout<<ans;
}
 
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>c[i],ve[c[i]].push_back(i);
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
        cin>>f[i];
    for(int i=1;i<=n;++i) for(int u:ve[i]) {
        ll tmp=mt();
        h[u]+=tmp;
        h[ve[i].front()]-=tmp;
    }
    for(int i=1;i<=n;++i)
        h[i]+=h[i-1];
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