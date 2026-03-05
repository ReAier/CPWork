#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e6+10,INF=0x3f3f3f3f;
ll mod=1e9+7;
const double eps=1e-8;
int n,m;

int ExGcd(int a,int b,int &x,int &y){
    if(!b) return x=1,y=0,a;
    int d=ExGcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}


ll inv[maxn];

void solve(){
    for(ll i=2;i<=n;++i)
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    for(int i=1;i<=n;++i)
        cout<<inv[i]<<'\n';
}

void init(){
    cin>>n>>mod;
    inv[1]=1;
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