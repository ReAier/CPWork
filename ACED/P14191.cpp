#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
// #define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
const double eps=1e-8;
ll n,m;
struct Seg{
    ll l,r,id;
    bool used;
    bool operator<(const Seg &x) const{
        return l<x.l;
    }
}a[maxn];
bool cmp(const Seg &x,const Seg &y) {
    return x.r>y.r;
}

void solve(){
    vector<int>ans1;
    ll ans=0;
    for(int i=1;i<=n;++i){
        if(a[i].l>=m){
            ans+=a[i].r-m;
            ans1.push_back(a[i].id);
            m=a[i].r;
            a[i].used=1;
        }else if(a[i].r>=m){
            ans+=a[i].r-a[i].l;
            ans1.push_back(a[i].id);
            m=a[i].r;
            a[i].used=1;
        }
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i){
        if(a[i].used) continue;
        ans+=a[i].r-a[i].l;
        ans1.push_back(a[i].id);
    }
    cout<<ans<<endl;
    for(int i:ans1) cout<<i<<" ";
    cout<<endl;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i].l>>a[i].r,a[i].id=i,a[i].used=0;
    sort(a+1,a+1+n);
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
#endif
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