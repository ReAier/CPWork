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

const int maxn=1e6+10,INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;
ll n,m;
struct Edge{
    ll u,v,w,id;
    bool used;
    bool operator<(Edge x){
        return w<x.w;
    }
}e[maxn];
int rt[maxn];
int Find(int x){
    return rt[x]==x?x:rt[x]=Find(rt[x]);
}
bool Merge(int u,int v){
    if(Find(u)==Find(v)) return 0;
    rt[Find(u)]=Find(v);
    return 1;
}
vector<pair<ll,ll>>g[maxn];
ll dep[maxn];
pair<ll,ll>fa[maxn];
void Dfs(int u,int pa){
    dep[u]=dep[pa]+1;
    for(auto [v,id]:g[u])
        if(v!=pa) Dfs(v,u),fa[v]={u,id};
}
ll ans[maxn];
void Change(int u,int v,ll w){
    if(dep[v]>dep[u])
        swap(u,v);
    while(dep[u]>dep[v]){
        auto [f,id]=fa[u];
        if(!ans[id]) ans[id]=w;
        u=f;
    }
    while(u!=v){
        auto [fu,idu]=fa[u];
        auto [fv,idv]=fa[v];
        if(!ans[idu]) ans[idu]=w;
        if(!ans[idv]) ans[idv]=w;
        u=fu,v=fv;
    }
}
void solve(){
    ll ans0=0;
    for(int i=1;i<=m;++i){
        if(Merge(e[i].u,e[i].v)){
            ans0+=e[i].w,e[i].used=1;
            g[e[i].u].push_back({e[i].v,e[i].id});
            g[e[i].v].push_back({e[i].u,e[i].id});
        }
    }
    Dfs(1,0);
    for(int i=1;i<=m;++i){
        if(!e[i].used)
            Change(e[i].u,e[i].v,e[i].w);
    }
    for(int i=1;i<=m;++i){
        if(ans[e[i].id]) ans[e[i].id]+=ans0-e[i].w; 
        else if(!e[i].used) ans[e[i].id]=ans0;
        else ans[e[i].id]=-1;
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        rt[i]=i;
    for(int i=1;i<=m;++i)
        cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=i;
    sort(e+1,e+1+m);
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