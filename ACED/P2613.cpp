#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=19260817;
const double eps=1e-8;
int n,m;

ll read(){
    ll res=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) {
        res=res*10+ch-'0';
        res%=mod;
        ch=getchar();
    }
    return res;
}

ll ExGcd(ll a,ll b,ll &x,ll &y){
    if(!b) return x=1,y=0,a;
    ll d=ExGcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}


void solve(){
    if(!m) 
        return printf("Angry!"),void();
    ll x,y;
    ExGcd(m,mod,x,y);
    x=((x%mod)+mod)%mod;
    cout<<(x*n)%mod;
}

void init(){
    n=read(),m=read();
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