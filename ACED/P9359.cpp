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
ll n,m,c,d,s,t,cnt;
struct Edge{
    int v,w,nx;
}e[maxn];
int head[maxn],idx=1;
void AddEdge(int u,int v,int w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
}
int cur[maxn],dis[maxn];
bool Bfs(){
    queue<int>q;
    for(int i=1;i<=t;++i) 
        cur[i]=head[i],dis[i]=INF;
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
int Dfs(int u,int las){
    if(u==t) return las;
    int res=0;
    for(int i=cur[u];i&&las;i=e[i].nx){
        cur[u]=i;
        int v=e[i].v,w=min(e[i].w,las);
        if(dis[v]==dis[u]+1&&w){
            int k=Dfs(v,w);
            las-=k,res+=k;
            e[i].w-=k,e[i^1].w+=k;
        }
    }
    if(!res) dis[u]=INF;
    return res;
}
ll Flow(){
    ll ans=0;
    while(Bfs())
        ans+=Dfs(s,INF);
    return ans;
}
ll Chack(int k){
    for(int i=head[s];i;i=e[i].nx) e[i].w=k,e[i^1].w=0;
    for(int i=head[t];i;i=e[i].nx) e[i^1].w=k,e[i].w=0;
    for(int u=1;u<=n;++u) for(int i=head[u];i;i=e[i].nx) if(e[i].v!=s)
        e[i].w=1,e[i^1].w=0;
    return (cnt-Flow())*d+c*k;
}

void solve(){
    ll res=cnt*d;
    int l=0,r=max(n,m);
    while(l<r){
        int mid=l+r>>1;
        if(Chack(mid)<Chack(mid+1)) r=mid;
        else l=mid+1;
    }
    cout<<Chack(l);
}

void init(){
    cin>>n>>m>>c>>d;
    s=n+m+1,t=n+m+2;
    char ch;
    for(int i=1;i<=n;++i) 
        AddEdge(s,i,1),AddEdge(i,s,0);
    for(int i=n+1;i<=n+m;++i) 
        AddEdge(i,t,1),AddEdge(t,i,0);
    for(int u=1;u<=n;++u) for(int v=n+1;v<=n+m;++v){
        cin>>ch;
        if(ch=='.') 
            AddEdge(u,v,1),AddEdge(v,u,0),++cnt;
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