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
int n,m,V=2e5+100;
int a[maxn],d[maxn],cnt[maxn],sum[maxn];
int ans[maxn];
void solve(){
    int las=0;
    for(int i=1;i<=V;++i){
        ans[i]=(sum[i]+las)%10;
        las=(sum[i]+las)/10;
    }
    while(!ans[V])--V;
    for(int i=V;i>=1;--i)
        cout<<ans[i];
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],cnt[a[i]]++;
    for(int i=V;i>=1;--i)
        sum[i]=sum[i+1]+cnt[i];
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