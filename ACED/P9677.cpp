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
int a[maxn],b[maxn];
bool bed[maxn];

void solve(){
    int ans=0;
    for(int i=n;i>=1;--i){
        if(bed[i]) continue;
        bed[i]=1;
        for(int j=i;j&&b[a[j]+1]<j;j=b[a[j]+1])
            bed[b[a[j]+1]]=1;
        ++ans;
    }
    cout<<ans<<'\n';
}

void init(){
    for(int i=1;i<=n;++i)
        b[i]=INF,bed[i]=0;
    cin>>n;
    for(int i=1;i<=n;++i)
        b[i]=INF,bed[i]=0;
    for(int i=1;i<=n;++i)
        cin>>a[i],b[a[i]]=i;
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