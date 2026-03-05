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
vector<int>e[maxn];
int dfn[maxn],low[maxn],idx,cnt,siz[maxn],scc[maxn];
stack<int>st;
bitset<maxn>ins;

void tarjan(int u){
    low[u]=dfn[u]=++idx;
    st.push(u);
    ins[u]=1;
    for(int v:e[u]){
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        cnt++;
        while(st.size()){
            int v=st.top();st.pop();
            siz[scc[v]=cnt]++;
            ins[v]=0;
            if(v==u) break;
        }
    }
}

void solve(){
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    int ans=0;
    for(int i=1;i<=cnt;++i) if(siz[i]>1) ++ans;
    cout<<ans;
}
void init(){
    cin>>n>>m;
    int u,v;
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