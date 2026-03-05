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
ll a[maxn],b[maxn],sum[maxn];

void solve(){
    int l,r;
    while(m--){
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<' ';
    }
    cout<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)   
        cin>>a[i];
    for(int i=1;i<=n;++i)   
        cin>>b[i],a[i]=max(a[i],b[i]);
    for(int i=n-1;i>=1;--i)
        a[i]=max(a[i],a[i+1]);
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+a[i];
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