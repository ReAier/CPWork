#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn],sum[maxn];



int ans[maxn];
void solve(){  
    for(int i=3;i<=n;++i){
        int l=-1,r=i-1;
        while(l<r){
            int mid=l+r>>1;
            if(sum[i-1]-sum[mid]>a[i]) l=mid;
            else r=mid-1;
        }
        for(int j=i-l;j<=i;++j)
            ans[j]=max(ans[j],sum[i]-sum[i-j]);
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
}
void init(){
    cin>>n;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
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