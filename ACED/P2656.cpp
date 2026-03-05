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
int n,m,s;
vector<tuple<int,int,long double>>e[maxn];

int dfn[maxn],low[maxn],tim;
int st[maxn],top;
bool ins[maxn];
int scc[maxn],num;

void Tarjan(int u){
    dfn[u]=low[u]=++tim;
    ins[st[++top]=u]=1;
    for(auto [v,w,k]:e[u]){
        if(!dfn[v]) 
            Tarjan(v),low[u]=min(low[u],low[v]);
        else if(ins[v]) 
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++num;
        while(1){
            scc[st[top]]=num;
            ins[st[top]]=0;
            if(st[top--]==u) break;
        }
    }
}

int a[maxn];
vector<pair<int,int>>ne[maxn];
int du[maxn];

int dp[maxn];
queue<int>q;
void Topo(){
    q.push(scc[s]);
    while(!q.empty()){
        int u=q.front();q.pop();
        dp[u]+=a[u];
        for(auto[v,w]:ne[u]){
            dp[v]=max(dp[v],dp[u]+w);
            if(!(--du[v])) 
                q.push(v);
        }
    }
}

void solve(){
    Tarjan(s);
    for(int u=1;u<=n;++u) for(auto [v,w,k]:e[u]){
        if(!scc[u]||!scc[v]) continue;
        if(scc[u]==scc[v])
            while(w) a[scc[u]]+=w,w*=k;
        else 
            ne[scc[u]].push_back({scc[v],w}),du[scc[v]]++;
    }
    Topo();
    int ans=0;
    for(int i=1;i<=num;++i) ans=max(ans,dp[i]);
    cout<<ans;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,w;
        long double k;
        cin>>u>>v>>w>>k;
        e[u].push_back({v,w,k});
    }
    cin>>s;
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