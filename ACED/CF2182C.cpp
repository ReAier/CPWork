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
ll n,m;
int a[maxn],b[maxn],c[maxn];
bool Chack(int *x,int *y){
    for(int i=1;i<=n;++i){
        if(x[i]>=y[i])
            return 0;
    }
    return 1;
}
void solve(){
    ll ans1=0,ans2=0;
    for(int i=0;i<n;++i){
        if(Chack(a,b+i))
            ans1++;
    }
    for(int i=0;i<n;++i){
        if(Chack(b,c+i))
            ans2++;
    }
    cout<<ans1*ans2*n<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i],b[i+n]=b[i];
    for(int i=1;i<=n;++i)
        cin>>c[i],c[i+n]=c[i];
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