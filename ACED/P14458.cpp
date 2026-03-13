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
ll a[maxn],sum[maxn],ans[maxn];

void solve(){
    int l=1,r=n;
    for(int i=n;i>=3;--i){
        while(l>1&&a[r]>=sum[r-1]-sum[l-1])
            --l,--r;
        if(a[r]<sum[r-1]-sum[l-1])
            ans[i]=sum[r]-sum[l-1];
        ++l;
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
}
void init(){
    cin>>n;m=n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+a[i],ans[i]=0;
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