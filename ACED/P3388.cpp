#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=4e4+10,INF=1e9+10,mod=1e9+7;
int n,m;
vector<int>e[maxn];

int dfn[maxn],low[maxn],rt,idx;
bool iscut[maxn];
vector<int>cut;

void tarjan(int u){
    dfn[u]=low[u]=++idx;
    int chd=0;
    for(int v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                if((++chd>1||u!=rt)&&!iscut[u]) 
                    iscut[u]=1,cut.push_back(u);
            }
        }else low[u]=min(low[u],dfn[v]);
    }
}

void solve(){
    for(int i=1;i<=n;++i) if(!dfn[i]) rt=i,tarjan(i);
    cout<<cut.size()<<endl;
    for(int i=1;i<=n;++i) if(iscut[i]) cout<<i<<" ";
}

void init(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;++i) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
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