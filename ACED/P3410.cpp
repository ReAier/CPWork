#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=2e4+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m,s,t;
struct Edge{
    ll v,w,nx;
}e[maxn];
ll head[maxn],idx=1,cur[maxn];
void AddEdge(ll u,ll v,ll w){
    e[++idx]=Edge{v,w,head[u]};
    head[u]=idx;
}

ll dis[maxn];
ll Dfs(int u,ll las){
    if(u==t) return las;
    ll res=0;
    for(int i=cur[u];i&&las;i=e[i].nx){
        cur[u]=i;
        ll v=e[i].v,w=min(las,e[i].w);
        if(dis[v]==dis[u]+1&&w){
            ll k=Dfs(v,w);
            res+=k,las-=k;
            e[i].w-=k,e[i^1].w+=k;
        }
    }
    if(!res) dis[u]=INF;
    return res;
}
queue<int>q;
bool Bfs(){
    for(int i=1;i<=t;++i)
        dis[i]=INF,cur[i]=head[i];
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nx){
            auto [v,w,nx]=e[i];
            if(dis[v]==INF&&w) 
                dis[v]=dis[u]+1,q.push(v);
        }
    }
    return dis[t]!=INF;
}
ll Dinic(){
    ll res=0;
    while(Bfs())
        res+=Dfs(s,INF);
    return res;
}
ll ans=0;
void solve(){
    cout<<ans-Dinic();
}
void init(){
    cin>>n>>m;
    s=n+m+1,t=n+m+2;
    ll w,v;
    for(int u=1;u<=n;++u){
        cin>>w;
        ans+=w;
        AddEdge(s,u,w),AddEdge(u,s,0);
        while(cin>>v){
            if(!v) break;
            AddEdge(u,v+n,INF),AddEdge(v+n,u,0);
        }
    }
    for(int i=1;i<=m;++i)
        cin>>w,AddEdge(i+n,t,w),AddEdge(t,i+n,0);
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