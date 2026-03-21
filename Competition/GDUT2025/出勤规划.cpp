#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
using namespace std;
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m,k;
vector<pii>e[maxn];
int a[maxn];

pii d[maxn];
priority_queue<pii>q;
bool vis[maxn];
void Dij(){
    while(q.size())
        q.pop();
    for(int i=1;i<=n;++i)
        d[i]={INF,0},vis[i]=0;
    for(int i=1;i<=k;++i)
        q.push({0,a[i]}),d[a[i]]={0,a[i]};
    
    while(q.size()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto[v,w]:e[u]) if(!vis[v]) {
            if(d[v].first>d[u].first+w){
                d[v]=d[u];
                d[v].first+=w;
                q.push({-d[v].first,v});
            }
        }
    }
}

struct Edge{
    ll u,v,w;
    bool operator<(const Edge &x)const{
        return w<x.w;
    }
}e2[maxn];
int fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
ll Krus(){
    sort(e2+1,e2+1+m);
    for(int i=1;i<=n;++i)  
        fa[i]=i;
    ll ans=0;

    for(int i=1;i<=m;++i){
        auto[u,v,w]=e2[i];
        u=find(u),v=find(v);
        if(u!=v)
            fa[u]=v,ans+=w;
    }
    return ans;
}

void solve(){
    Dij();
    m=0;
    for(int u=1;u<=n;++u) for(auto[v,w]:e[u]) 
        if(d[u].second!=d[v].second) 
            e2[++m]={d[u].second,d[v].second,d[u].first+d[v].first+w};
    cout<<Krus()<<'\n';
}
void init(){
    cin>>n>>m>>k;   
    for(int i=1;i<=n;++i)
        e[i].clear();
    int u,v,w;
    for(int i=1;i<=m;++i)
        cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
    for(int i=1;i<=k;++i)
        cin>>a[i];
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