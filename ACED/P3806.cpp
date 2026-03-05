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
const int maxn=1e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
vector<pii>e[maxn];
bitset<maxn>vis,ans;
int siz[maxn],rt,mxp[maxn];
void GetRoot(int u,int fa,int tot){
    siz[u]=1,mxp[u]=0;
    for(auto[v,w]:e[u]) if(v!=fa&&!vis[v])
        GetRoot(v,u,tot),siz[u]+=siz[v],mxp[u]=max(mxp[u],siz[v]);
    mxp[u]=max(mxp[u],tot-siz[u]);
    if(mxp[u]<mxp[rt]) rt=u;
}
int Qu[maxn];
int dis[maxn];
bitset<int(1e7)+10>cnt;
vector<int>d,las;
void Dfs(int u,int fa){
    d.push_back(dis[u]);
    for(auto[v,w]:e[u]) if(v!=fa&&!vis[v])
        dis[v]=dis[u]+w,Dfs(v,u);
}
void Calc(int u){
    cnt[0]=1;
    for(auto [v,w]:e[u])if(!vis[v]){
        dis[v]=w;
        d.clear();
        Dfs(v,u);
        for(int k:d) for(int i=1;i<=m;++i)
            if(Qu[i]>=k&&cnt[Qu[i]-k]) 
                ans[i]=1;
        for(int k:d) if(k<=1e7) 
            cnt[k]=1,las.push_back(k);
    }
    for(int k:las) cnt[k]=0;
    las.clear();
}
void Divide(int u){
    vis[u]=1;
    Calc(u);
    for(auto [v,w]:e[u]) if(!vis[v]){
        rt=0;
        GetRoot(v,u,siz[v]);
        Divide(rt);
    }
}

void solve(){
    GetRoot(1,0,n);
    Divide(rt);
    for(int i=1;i<=m;++i)
        cout<<(ans[i]?"AYE\n":"NAY\n");
}
void init(){
    cin>>n>>m;
    mxp[0]=INF;
    int u,v,w;
    for(int i=1;i<n;++i)
        cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
    for(int i=1;i<=m;++i)
        cin>>Qu[i];
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