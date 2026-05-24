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
ll n,m;
ll a[maxn],S,B,C;

ll ExGcd(ll a,ll b,ll &x,ll &y){
    if(!b) return x=1,y=0,a;
    ll d=ExGcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

void solve() {
    ll x1,y1,x2,y2;
    ll g1=ExGcd(B,C,x1,y1);
    ll g2=ExGcd(g1,m,x2,y2);
    ll ans=S%g2,K=((ans-S+m)%m)/g2;
    ll s=((x1*x2)%m)*K%m,d=((y1*x2)%m)*K%m;
    cout<<ans<<"\n"<<(s+m)%m<<" "<<(d+m)%m<<'\n';
}
void init() {
    cin>>n>>m;
    B=n%m,C=((n*(n+1))/2)%m;
    for(int i=1;i<=n;++i)
        cin>>a[i],S=(S+a[i])%m;
}
int main() {
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
    // while(cin>>n) {
    while(T--) {
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}