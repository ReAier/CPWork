#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=2e5+10,INF=0x3f3f3f3f;
const double eps=1e-8;
ll n,m,K,mod;
vector<pair<ll,ll>>e[maxn],ne[maxn];

ll d[maxn];
bool vis1[maxn];
void Dijstra(ll s){
    priority_queue<pair<ll,ll>>q;
    memset(d,0x3f,sizeof(d));
    memset(vis1,0,sizeof(vis1));
    q.push({0,s});
    d[s]=0;
    while(!q.empty()){
        auto u=q.top().second;q.pop();
        if(vis1[u]) continue;
        vis1[u]=1;
        for(auto [v,w]:e[u]){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!vis1[v]) q.push({-d[v],v});
            }
        }
    }
}

ll dp[maxn][60];
bool vis[maxn][60],has0;
ll dfs(ll u,ll k){
    if(k<0||k>K) return 0;
    if(vis[u][k]){
        has0=1;
        return 0;
    }
    if(~dp[u][k]) return dp[u][k];
    
    vis[u][k]=1;
    dp[u][k]=0;
    for(auto [v,w]:ne[u]){
        dp[u][k]+=dfs(v,d[u]-d[v]+k-w);
        if(has0) return 0;
        dp[u][k]%=mod;
    }
    vis[u][k]=0;
    if(u==1&&k==0) return dp[1][0]=1;
    return dp[u][k];
}

void solve(){
    Dijstra(1);
    ll ans=0;
    for(ll i=0;i<=K;++i) {
        dfs(n,i),ans=(ans+dp[n][i])%mod;
        if(has0) break;
    } 
    if(has0) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}

void init(){
    cin>>n>>m>>K>>mod;
    for(ll i=1;i<=n;++i) e[i].clear(),ne[i].clear();
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    has0=0;
    ll u,v,w;
    for(ll i=1;i<=m;++i) 
        cin>>u>>v>>w,e[u].push_back({v,w}),ne[v].push_back({u,w});
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