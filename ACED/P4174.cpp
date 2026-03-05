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
int n,m,s,t;
struct Edge{
    int v,w,nx;
}e[maxn];
int head[maxn],idx=1,cur[maxn];
void AddEdge(int u,int v,int w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
}
int dis[maxn];
int Dfs(int u,int las){
    if(u==t) return las;
    int res=0;
    for(int i=cur[u];i&&las;i=e[i].nx){
        cur[u]=i;
        int v=e[i].v,w=min(las,e[i].w);
        if(w&&dis[u]+1==dis[v]){
            int k=Dfs(v,w);
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
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nx){
            auto [v,w,nx]=e[i];
            if(dis[v]==INF&&w) dis[v]=dis[u]+1,q.push(v);
        }
    }
    return dis[t]!=INF;
}
int Dinic(){
    int res=0;
    while(Bfs())
        res+=Dfs(s,INF);
    return res;
}
int ans=0;
void solve(){
    cout<<ans-Dinic();
}
void init(){
    cin>>n>>m;
    s=n+m+1,t=n+m+2;
    int w,u,v;
    for(int i=1;i<=n;++i)
        cin>>w,AddEdge(i,t,w),AddEdge(t,i,0);
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        ans+=w;
        AddEdge(n+i,u,INF),AddEdge(u,n+i,0);
        AddEdge(n+i,v,INF),AddEdge(v,n+i,0);
        AddEdge(s,n+i,w),AddEdge(n+i,s,0);
    }
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