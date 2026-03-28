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
vector<int>e[maxn];
vector<pii>q[maxn];
ll a[maxn],ans[maxn],b[maxn],mi[maxn],mi2[maxn];

void Dfs0(int u,int fa){
    for(int v:e[u]) if(v!=fa) {
        Dfs0(v,u);
        if(!mi[u]||a[mi[u]]>a[v]){
            if(mi[u]) mi2[u]=mi[u],mi[u]=v;
            else mi[u]=v;
        }else if(!mi2[u]||a[mi2[u]]>a[v])
            mi2[u]=v;
    }
    if(mi[u]) a[u]=min(a[u],a[mi[u]]+a[mi2[u]]);
}

void Dfs(int u,int fa,ll las){
    for(auto[v,id]:q[u]){
        if(b[v]!=INF)
            ans[id]=b[v]+las;
        else ans[id]=-1;
    }
    if(!mi[u]) return;
    b[u]=-las;
    Dfs(mi[u],u,las+a[mi2[u]]);
    for(int v:e[u]) if(v!=fa&&v!=mi[u])
        Dfs(v,u,las+a[mi[u]]);
    b[u]=INF;
}
void solve(){
    Dfs0(1,0);
    Dfs(1,0,0);
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<"\n";
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) 
        cin>>a[i],q[i].clear(),e[i].clear(),b[i]=INF,mi[i]=mi2[i]=0;
    int u,v;
    for(int i=1;i<n;++i) 
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    for(int i=1;i<=m;++i)
        cin>>u>>v,q[u].push_back({v,i});
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