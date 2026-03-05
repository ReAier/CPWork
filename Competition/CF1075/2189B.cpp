#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m;
ll a[maxn],b[maxn],c[maxn];
pii v1[maxn];

void solve(){
    ll sum=0;
    for(int i=1;i<=n;++i) 
        sum+=(b[i]-1)*a[i];
    if(sum>=m) return cout<<"0\n",void();
    if(v1[1].first<=0) return cout<<"-1\n",void();
    m=m-sum;
    cout<<(m/v1[1].first)+bool(m%v1[1].first)<<'\n'; 
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
        v1[i].first=b[i]*a[i]-c[i];
        v1[i].second=i;
    }
    sort(v1+1,v1+1+n,greater<pii>());
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