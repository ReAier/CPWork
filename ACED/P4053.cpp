#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
ll n,m;
struct node{
    ll a,b;
    bool operator<(const node &x)const {
        return a<x.a;
    }
}a[maxn];
bool cmp(const node &x,const node &y){
    return x.b<y.b;
}

priority_queue<node>q;

void solve(){
    ll ans=0,ti=0;
    for(int i=1;i<=n;++i){
        ti+=a[i].a;
        ++ans;
        q.push(a[i]);
        if(ti>a[i].b) ti-=q.top().a,q.pop(),--ans;
    }
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].a>>a[i].b;
    sort(a+1,a+1+n,cmp);
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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