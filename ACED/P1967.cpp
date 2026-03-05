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
    int u,v,w;
    bool operator<(const Edge &x) const{
        return w>x.w;
    }
}E[maxn];
int rt[maxn];
int Find(int x){
    if(x==rt[x]) return x;
    return rt[x]=Find(rt[x]);
}
void Merge(int u,int v){
    rt[Find(u)]=Find(v);
}
vector<pair<int,int>>e[maxn];

int fa[maxn][20],mi[maxn][20],dep[maxn];
void Dfs(int u,int fat){
    fa[u][0]=fat;
    dep[u]=dep[fat]+1;
    for(auto [v,w]:e[u]){
        if(v==fat) continue; 
        mi[v][0]=w;
        Dfs(v,u);
    }
}

int GetMin(int u,int v){
    if(Find(u)!=Find(v)) return -1;
    if(dep[u]<dep[v]) swap(u,v);
    int ans=INF,dif=dep[u]-dep[v];
    for(int i=18;i>=0;--i) if(dif&(1<<i)){
        ans=min(ans,mi[u][i]);
        u=fa[u][i];
    }
    if(u==v) return ans;
    for(int i=18;i>=0;--i){
        if(fa[u][i]==fa[v][i]) continue;
        ans=min(ans,min(mi[u][i],mi[v][i]));
        u=fa[u][i],v=fa[v][i];
    }
    ans=min(ans,min(mi[u][0],mi[v][0]));
    return ans;
}

void solve(){
    int u,v,w,q;
    for(int i=1;i<=m;++i){
        u=E[i].u,v=E[i].v,w=E[i].w;
        if(Find(u)!=Find(v)) {
            e[u].push_back({v,w});
            e[v].push_back({u,w});
            Merge(u,v);
        }
    }
    for(int i=1;i<=n;++i) if(!dep[i]) Dfs(i,0);
    for(int i=1;i<=18;++i) for(int j=1;j<=n;++j){
        fa[j][i]=fa[fa[j][i-1]][i-1];
        mi[j][i]=min(mi[j][i-1],mi[fa[j][i-1]][i-1]);
    }
    cin>>q;
    while(q--){
        cin>>u>>v;
        cout<<GetMin(u,v)<<'\n';
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        cin>>E[i].u>>E[i].v>>E[i].w;
    sort(E+1,E+1+m);
    for(int i=1;i<=n;++i) rt[i]=i;
    memset(mi,0x3f,sizeof(mi));
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