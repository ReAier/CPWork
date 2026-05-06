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
const int maxn=100+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m,p,y;
double a[maxn],mp[maxn][maxn][maxn],b[maxn][maxn];

struct Edge{
    int v;
    double w;
    int nx;
}e[int(1e6)];
int head[maxn*maxn],idx=1;
void AddEdge(int u,int v,double w){
    e[++idx]={v,w,head[u]};
    head[u]=idx;
    e[++idx]={u,0,head[v]};
    head[v]=idx;
}
int s,t,cur[maxn*maxn],dis[maxn*maxn];
double Dfs(int u,double las){
    if(u==t) return las;
    double res=0;
    for(int i=cur[u];i&&las;i=e[i].nx){
        cur[u]=i;
        int v=e[i].v;
        double w=min(las,e[i].w);
        if(dis[v]==dis[u]+1&&w>eps){
            double k=Dfs(v,w);
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
            int v=e[i].v;
            double w=e[i].w;
            if(dis[v]==INF&&w>eps)
                dis[v]=dis[u]+1,q.push(v);
        }
    }
    return dis[t]!=INF;
}
double Flow(int S,int T){
    double ans=0;
    s=S,t=T;
    while(Bfs(s,t)&&ans<=1e10+eps)
        ans+=Dfs(s,1e10);
    return ans;
}
int GetID(int x,int y){
    return (x-1)*(m+1)+y;
}

void solve(){
    double ans=Flow(s,t);
    if(ans>=1e10) cout<<"-1\n";
    else cout<<fixed<<setprecision(4)<<ans<<'\n';
}
void init(){
    idx=1;
    cin>>n>>m>>p>>y;
    s=GetID(n,m+1)+1,t=GetID(n,m+1)+2;
    for(int i=1;i<=t;++i)
        head[i]=0;
    for(int i=1;i<=p;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) for(int k=1;k<=p;++k)
        cin>>mp[j][i][k];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            double P=1;
            b[i][j]=0;
            for(int k=1;k<=p;++k){
                P*=mp[i][j][k];
                b[i][j]+=P*a[k];
            }
        }
        AddEdge(s,GetID(i,1),1e10);
        AddEdge(GetID(i,m+1),t,1e10);
        for(int j=1;j<=m;++j)   
            AddEdge(GetID(i,j),GetID(i,j+1),b[i][j]),AddEdge(GetID(i,j+1),GetID(i,j),1e10);
    }
    int u,v,w;
    for(int i=1;i<=y;++i){
        cin>>u>>v>>w;
        for(int j=1;j<=m;++j)   
            AddEdge(GetID(v,j),GetID(u,max(1,min(j+w,m+1))),1e10);
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
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int T=1;
    cin>>T;
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