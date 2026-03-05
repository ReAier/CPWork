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
vector<int>pos[maxn];
ll res;
set<pii>s;
ll GetVal(ll r){
    return r*(r+1)/2;
}
ll GetSeg(ll x){
    auto it=s.lower_bound({x,-INF});
    auto [r,l]=*it;
    if(it==s.end()||x>r||x<l)
        return 0;
    res-=GetVal(r-l+1);
    s.erase(it);
    return r-l+1;
}
void Insert(ll x){
    ll llen=0,rlen=0;
    if(x>1)
        llen=GetSeg(x-1);
    if(x<n-1)
        rlen=GetSeg(x+1);
    res+=GetVal(llen+rlen+1);
    s.insert({x+rlen,x-llen});
}

ll ans[maxn];
void solve(){   
    for(int i=n-1;i>=1;--i){
        for(int u:pos[i])
            Insert(u);
        ans[i]=res;
    }
    for(int i=1;i<n;++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
}   
void init(){
    cin>>n;
    res=0;
    s.clear();
    for(int i=1;i<=n;++i)
        pos[i].clear();
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<n;++i)
        pos[abs(a[i]-a[i+1])].push_back(i);
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