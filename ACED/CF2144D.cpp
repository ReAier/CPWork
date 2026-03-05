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
const ll maxn=2e5+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m,V=2e5;
int cnt[maxn],sum[maxn];

void solve(){
    ll ans=-m*n;
    for(int x=2;x<=V;++x){
        ll now=-m*n;
        for(ll i=1;(i-1)*x+1<=V;++i){
            int l=(i-1)*x+1,r=min(i*x,V),c=sum[r]-sum[l-1];
            if(c) now+=min(c,cnt[i])*m+i*c;
        }
        ans=max(ans,now);
    }
    cout<<ans<<'\n';
}
void init(){
    cin>>n>>m;
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));
    ll c;V=0;
    for(int i=1;i<=n;++i)
        cin>>c,cnt[c]++,V=max(V,c+1);
    for(int i=1;i<=V;++i)
        sum[i]=sum[i-1]+cnt[i];
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