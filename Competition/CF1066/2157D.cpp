#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8; 
ll n,m;
ll L,R,a[maxn];
int cha[maxn];

void solve(){
    ll ans=0;
    ll l=1,r=n;
    while(a[l]<=L) cha[l]=1,(l<n-l+1)?cha[n-l+1]=2:0,++l;
    while(a[r]>=R) cha[r]=2,(r>n-r+1)?cha[n-r+1]=1:0,--r;
    for(int i=1;i<=n/2;++i) if(!cha[i]&&!cha[n-i+1]) cha[i]=1,cha[n-i+1]=2;
    ll _1=0,_2=0;
    for(int i=1;i<=n;++i) _1+=cha[i]==1,_2+=cha[i]==2;

    ll pos=_1<_2?R:L;
    for(int i=1;i<=n;++i)
        if(cha[i]==1){
            ans+=pos-a[i];
        }else if(cha[i]==2){
            ans+=a[i]-pos;
        }
    cout<<ans<<'\n';
}

void init(){
    cin>>n>>L>>R;
    for(int i=1;i<=n;++i)   
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) cha[i]=0;
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