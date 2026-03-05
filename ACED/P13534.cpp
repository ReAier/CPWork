#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
#define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const ll maxn=1e3+10,INF=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const double eps=1e-8;
int n,m,p;
ll a[maxn];
vector<pair<int,int>>e[maxn];
struct Node{
    ll id,cnt,mon,mx;
    inline bool operator<(const Node x)const{
        return cnt==x.cnt?mon<x.mon:cnt>x.cnt;
    }
};
struct Dis{
    ll cnt,mon;
    Dis(ll cnt=INF,ll mon=-1):cnt(cnt),mon(mon){}
    inline bool operator<(Dis x){
        return cnt==x.cnt?mon>x.mon:cnt<x.cnt;
    }
}d[maxn][maxn];
priority_queue<Node>q;
inline void Dijstra(){
    d[1][1]={0,p};
    q.push({1,0,p,1});
    while(!q.empty()){
        auto [u,cnt,mon,mx]=q.top();q.pop();
        if(d[u][mx]<(Dis){cnt,mon}) 
            continue;
        for(auto [v,w]:e[u]){
            ll tmp=0,nmx=((a[mx]<a[v])?v:mx);
            if(mon<w) tmp=(w-mon)/a[mx]+((w-mon)%a[mx]!=0);
            Dis d2={cnt+tmp,mon+a[mx]*tmp-w};
            if(d2<d[v][nmx]) 
                d[v][nmx]=d2,q.push({v,d2.cnt,d2.mon,nmx});
        }
    }
}
inline void solve(){
    Dijstra();
    ll ans=INF;
    for(ll i=1;i<=n;++i) 
        ans=min(ans,d[n][i].cnt);
    cout<<(ans==INF?-1:ans);
}

inline void init(){
    ll c;
    cin>>n>>m>>p>>c;
    for(ll i=1;i<=n;++i)
        cin>>a[i];
    ll u,v,w;
    for(ll i=1;i<=m;++i)
        cin>>u>>v>>w,e[u].push_back({v,w});
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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