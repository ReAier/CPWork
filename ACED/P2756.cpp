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
int n,m;
struct Edge{
    int v,w,nx;
}e[maxn];
int head[maxn],idx=1,s,t;
void AddEdge(int u,int v,int w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
}
int cur[maxn],dis[maxn];
bool Bfs(){
    for(int i=1;i<=n+2;++i) 
        cur[i]=head[i],dis[i]=INF;
    queue<int>q;
    dis[s]=0;
    q.push(s);
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
int Dfs(int u,int las){
    if(u==t) return las;
    int res=0;
    for(int i=cur[u];i&&las;i=e[i].nx){
        cur[u]=i;
        int v=e[i].v,w=min(las,e[i].w);
        if(dis[v]==dis[u]+1&&w){
            int k=Dfs(v,w);
            res+=k,las-=k;
            e[i].w-=k,e[i^1].w+=k;
        }
    }
    if(!res) dis[u]=INF;
    return res;
}

int Flow(){
    int ans=0;
    while(1){
        if(!Bfs()) break;
        ans+=Dfs(s,INF);
    }
    return ans;
}

void solve(){
    cout<<Flow()<<'\n';
    for(int u=1;u<=m;++u){  
        for(int i=head[u];i;i=e[i].nx) {
            if(!e[i].w&&e[i].v<=n){
                cout<<u<<" "<<e[i].v<<'\n';
            }
        }
    }
}

void init(){
    cin>>m>>n;
    s=n+1,t=n+2;
    for(int i=1;i<=m;++i) 
        AddEdge(n+1,i,1),AddEdge(i,n+1,0);
    for(int i=m+1;i<=n;++i) 
        AddEdge(i,n+2,1),AddEdge(n+2,i,0);
    int u=1,v;
    while(~u){
        cin>>u>>v;
        AddEdge(u,v,1);
        AddEdge(v,u,0);
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