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
const int maxn=3e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m,q;
int a[maxn],c[maxn],d[maxn],f[maxn];
struct Edge{
    int u,v;
}e[maxn];
vector<int>b[maxn];
bool vis[maxn];

inline void Add(int x,int k){
    a[x]+=k;
    for(int v:b[x])
        c[v]+=k;
}
inline int Query(int x){
    int ans=c[x];
    for(int v:b[x])
        ans+=a[v];
    return ans;
}
struct Query{
    int opt,x,k;
}Q[maxn];

void solve(){
    for(int i=1;i<=q;++i){
        auto[opt,x,k]=Q[i];
        if(opt==1) Add(x,k);
        else cout<<Query(x)<<'\n';
    }
}
void init(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;++i)
        cin>>e[i].u>>e[i].v;
    for(int i=1;i<=n;++i)
        cin>>f[i];
    for(int i=1;i<=q;++i){
        cin>>Q[i].opt>>Q[i].x;
        if(Q[i].opt==1)
            cin>>Q[i].k;
        d[Q[i].x]++;
    }
    for(int i=1;i<=m;++i){
        auto[u,v]=e[i];
        if(d[u]>d[v]) swap(u,v);
        b[u].push_back(v);
    }
    for(int i=1;i<=n;++i)
        Add(i,f[i]);
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
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