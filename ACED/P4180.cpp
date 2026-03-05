#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Edge{
    ll u,v,w;
    bool operator<(const Edge &x) const{
        return w<x.w;
    }
}E[maxn];
bool used[maxn];

int rt[maxn];
int Find(int x){
    return x==rt[x]?x:rt[x]=Find(rt[x]);
}
void Merge(int u,int v){
    rt[Find(u)]=Find(v);
}

vector<pair<int,int>>e[maxn];

ll fa[maxn][20],dep[maxn];
struct Node{
    int max1,max2;
    Node operator+(const Node &x) const{
        Node res=(Node){0,0};
        res.max1=max(max1,x.max1);
        res.max2=max(max2,x.max2);
        if(max1<x.max1) res.max2=max(res.max2,max1);
        else if(max1>x.max1) res.max2=max(res.max2,x.max1);
        return res;
    }
}ma[maxn][20];
void Dfs(int u,int fat){
    dep[u]=dep[fa[u][0]=fat]+1;
    for(auto [v,w]:e[u]) if(v!=fat){
        ma[v][0].max1=w;
        Dfs(v,u);
    }
}

Node GetMax(ll u,ll v){
    if(dep[u]<dep[v]) swap(u,v);
    ll dif=dep[u]-dep[v];
    Node ans=(Node){0,0};
    for(int i=18;i>=0;--i) if(dif&(1<<i)) {
        ans=ans+ma[u][i];
        u=fa[u][i];
    }
    if(u==v) return ans;
    for(int i=18;i>=0;--i) if(fa[u][i]!=fa[v][i]){
        ans=ans+ma[u][i]+ma[v][i];
        u=fa[u][i],v=fa[v][i];
    }
    ans=ans+ma[u][0]+ma[v][0];
    return ans;
}

void solve(){
    ll mians=0,ans=INF;
    for(int i=1;i<=m;++i){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        if(Find(u)==Find(v)) continue;
        e[u].push_back({v,w});e[v].push_back({u,w});
        Merge(u,v);
        mians+=w;
        used[i]=1;
    }
    Dfs(1,0);
    for(int i=1;i<=18;++i) for(int j=1;j<=n;++j){
        fa[j][i]=fa[fa[j][i-1]][i-1];
        ma[j][i]=ma[j][i-1]+ma[fa[j][i-1]][i-1];
    }
    for(int i=1;i<=m;++i) if(!used[i]){
        ll u=E[i].u,v=E[i].v,w=E[i].w,nans;
        if(u==v) continue;
        auto [ans1,ans2]=GetMax(u,v);
        if(w==ans1) 
            nans=mians-ans2+w;
        else
            nans=mians+w-ans1;
        if(nans>mians) ans=min(ans,nans);
    }
    cout<<ans;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=m;++i) cin>>E[i].u>>E[i].v>>E[i].w;
    sort(E+1,E+1+m);
    for(int i=1;i<=n;++i) rt[i]=i;
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