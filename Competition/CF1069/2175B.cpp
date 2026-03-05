#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9-10;
const double eps=1e-8;
int n,m;
int l,r;
mt19937 mt(23353);

int a[maxn];
void solve(){

    for(int i=n;i>=1;--i) a[i]^=a[i-1];
    // for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j){
    //     int res=0;
    //     for(int k=i;k<=j;++k) res^=a[k];
    //     cout<<i<<" "<<j<<endl;
    //     cout<<res<<endl;
    // }
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
    cout<<'\n';
}

void init(){
    cin>>n>>l>>r;
    for(int i=0;i<=n;++i)
        a[i]=i;
    a[l-1]=a[r]=maxn;
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