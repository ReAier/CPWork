#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
#endif
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=2000+10,INF=1e9+10,mod=1e9+7;
int n,m,k,cnt;
vector<int>cow,e[maxn];
bitset<2000>vis[maxn];
int s;
void dfs(int u){
    if(vis[s][u]) return;
    vis[s][u]=1;
    for(auto v:e[u]) dfs(v);
}

void solve(){
    int lasti=-1;
    for(auto i:cow){
        s=i;
        dfs(i);
        if(lasti!=-1) 
            vis[i]&=vis[lasti];
        lasti=i;
    }
    cout<<vis[lasti].count();
}
void init(){
    cin>>k>>n>>m;
    cnt=n;
    int u,v;
    while(k--){
        cin>>u;
        cow.push_back(u);
    }
    while(m--){
        cin>>u>>v;
        e[u].push_back(v);
    }
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T=1;
    // cin>>T;
    while(T--){
        init();
        solve();
    }
    AC
}