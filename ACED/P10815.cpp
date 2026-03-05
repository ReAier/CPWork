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
ll n,m;

char buf[maxn<<4],*_s,*_t;
#define gc() (_s==_t && (_t=(_s=buf)+fread(buf,1,1<<20,stdin)),*_s++)
void read(ll &x){
    int f=1;x=0;
    char ch=gc();
    for(;!isdigit(ch);ch=gc())
        if(ch=='-') f=-1;
    for(;isdigit(ch);ch=gc())
        x=x*10+ch-'0';
    x*=f;
}


void solve(){
}

void init(){
    read(n);
    ll sum=0,a;
    for(int i=1;i<=n;++i)
        read(a),sum+=a;
    cout<<sum;
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