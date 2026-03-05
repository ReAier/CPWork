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

const int maxn=1e5+10,INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;
int n,m,k;
int a[maxn];
struct Node{
    ll id,val,t;
    bool operator<(const Node &x) const{
        if(val*x.t!=x.val*t) return val*x.t<x.val*t;
        if((t==1)^(x.t==1)) return t!=1;
        if(val!=x.val) return val<x.val;
        return id>x.id;
    }
};
set<Node>s;

int ans[maxn];
void solve(){
    while((((*--s.end()).val-(*s.begin()).val-1.0)>=0)||m%n){
        if(!m) break;
        auto u=*--s.end();
        s.erase(u);
        ans[u.id]++;
        u.t<<=1;
        s.insert(u);
        m--;
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]+m/n<<" ";
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)   
        s.insert({i,a[i],1});
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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
