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
int a[maxn];

void solve(){
    if(n&1) return cout<<a[n],void();
    int now=a[1]+a[n],flg=1;
    while(a[m]==a[n]) --m;
    for(int i=1;i<=(m/2);++i) if(a[i]+a[m-i+1]!=a[n]){
        flg=0;
        break;
    }
    if(flg&&(m&1)==0) cout<<a[n]<<" ";
    flg=1;
    for(int i=2;i<=n/2;++i) if(a[i]+a[n-i+1]!=now){
        flg=0;
        break;
    }
    if(flg) cout<<now;
}
void init(){
    cin>>n;m=n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
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