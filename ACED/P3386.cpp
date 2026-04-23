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
int s,t;
int dis[maxn],cur[maxn];
struct Edge{
    ll v,w,nx;
}e[maxn];
int head[maxn],idx=1;
void AddEdge(int u,int v,int w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
}
bool Bfs(int s,int t){
    queue<int>q;
    memcpy(cur,head,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nx){
            int v=e[i].v,w=e[i].w;
            if(dis[v]==INF&&w)
                dis[v]=dis[u]+1,q.push(v);
        }
    }
    return dis[t]!=INF;
}
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
ll Flow(int S,int T){
    ll ans=0;
    s=S,t=T;
    while(Bfs(s,t))
        ans+=Dfs(s,INF);
    return ans;
}
void solve(){
    cout<<Flow(n+1,n+2)<<'\n';
}
void init(){
    int a,b,u,v;
    cin>>a>>b>>m;
    n=a+b;
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        AddEdge(u,v+a,1);
        AddEdge(v+a,u,0);
    }
    for(int i=1;i<=a;++i){
        AddEdge(n+1,i,1);
        AddEdge(i,n+1,0);
    }
    for(int i=1;i<=b;++i){
        AddEdge(i+a,n+2,1);
        AddEdge(n+2,i+a,0);
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