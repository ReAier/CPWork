#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
vector<int>e[maxn],ne[maxn];
int a[maxn],dfn[maxn],low[maxn],idx,scc[maxn],cnt,w[maxn];
stack<int>st;
bitset<maxn>ins;

void tarjan(int u){
    st.push(u);ins[u]=1;
    dfn[u]=low[u]=++idx;
    for(int v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        cnt++;
        while(st.size()){
            int v=st.top();st.pop();
            scc[v]=cnt;
            w[cnt]+=a[v];
            ins[v]=0;
            if(v==u) break;
        }
    }
}


int din[maxn];
vector<int>tpst;
bitset<maxn>vis;
void topo(int s){
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        tpst.push_back(u);
        vis[u]=1;
        for(int v:ne[u]) if(!--din[v]) q.push(v);
    }
}
int dp[maxn];
void solve(){
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    for(int u=1;u<=n;++u) for(int v:e[u]) if(scc[u]!=scc[v]) ne[scc[u]].push_back(scc[v]),din[scc[v]]++;
    for(int i=1;i<=cnt;++i){
        if(!din[i]&&!vis[i]) topo(i),dp[i]=w[i];
    }
    for(int i=0;i<tpst.size();++i){
        for(int v:ne[tpst[i]]){
            dp[v]=max(dp[v],dp[tpst[i]]+w[v]);
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;++i){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}

void init(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>u>>v,e[u].push_back(v);
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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