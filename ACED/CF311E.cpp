#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll int
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const ll maxn=1e5+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m,g;
struct Edge{
    ll v,w,nx;
}e[maxn];
int head[maxn],idx=1;
void AddEdge(int u,int v,ll w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
    e[++idx]={u,0,head[v]};
    head[v]=idx;
}
ll a[maxn],sum;


int s,t,cur[maxn],dis[maxn];
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
ll Flow(){
    ll ans=0;
    while(Bfs(s,t))
        ans+=Dfs(s,INF);
    return ans;
}

void solve(){
    cout<<sum-Flow()<<'\n';
}
void init(){
    cin>>n>>m>>g;
    s=n+m+1,t=n+m+2;
    int u,v,w,x;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i){
        cin>>w;
        if(a[i]) AddEdge(i,t,w);
        else AddEdge(s,i,w);
    }
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        sum+=v;
        for(int j=1;j<=w;++j)
            cin>>a[j];
        cin>>x;
        for(int j=1;j<=w;++j){
            if(u) AddEdge(a[j],n+i,INF);
            else AddEdge(n+i,a[j],INF);
        }
        if(u) AddEdge(n+i,t,v+x*g);
        else AddEdge(s,n+i,v+x*g);
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