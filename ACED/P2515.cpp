#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=600+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int c[maxn],a[maxn],nc[maxn],na[maxn];
vector<int>e[maxn],ne[maxn];
int dp[maxn][maxn];

int s[maxn],top; //判断scc,edcc,vdcc
bool ins[maxn];
int dfn[maxn],low[maxn],tim;
int num,scc[maxn];
void Tarjan(int u){ 
    dfn[u] = low[u] = ++tim;
    s[++top]=u;
    ins[u]=1; 
    int child=0;
    for (int v:e[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            ++child;
            low[u] = min(low[u], low[v]);
        } else if(ins[v])
            low[u] = min(low[u], dfn[v]);   
    }
    if(dfn[u]==low[u]){    
        ++num;
        while(1){
            nc[num]+=c[s[top]];
            na[num]+=a[s[top]];
            scc[s[top]]=num;
            ins[s[top]]=0;
            if(s[top--]==u) break;
        }
        dp[num][nc[num]]=na[num];
    }
}

void dfs(int u){
    for(int v:ne[u]) {
        dfs(v);
        for(int i=m;i>nc[u];--i) for(int j=i-nc[u];j>=1;--j)
            dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
    }
}

int du[maxn];
void solve(){
    for(int i=1;i<=n;++i) if(!dfn[i])
        Tarjan(i);
    for(int u=1;u<=n;++u) for(int v:e[u]) if(scc[u]!=scc[v])
        ne[scc[u]].push_back(scc[v]),du[scc[v]]++;

    for(int i=1;i<=num;++i) if(!du[i])
        ne[0].push_back(i);
    
    dfs(0);

    int ans=0;
    for(int i=1;i<=m;++i) ans=max(ans,dp[0][i]);
    cout<<ans;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) 
        cin>>c[i];
    for(int i=1;i<=n;++i) 
        cin>>a[i];
    int u;
    for(int i=1;i<=n;++i) 
        cin>>u,e[u].push_back(i);
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