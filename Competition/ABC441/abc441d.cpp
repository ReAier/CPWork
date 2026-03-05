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
int n,m,l,s,t;
vector<pii>e[maxn];
bool ans[maxn];
void Dfs(int u,int lasl,int lasw){
    // cout<<u<<" "<<lasl<<" "<<lasw<<endl;
    if(lasw>t||lasl>l) return;
    if(lasw>=s&&lasw<=t&&lasl==l) 
        ans[u]=1;
    for(auto [v,w]:e[u]) 
        Dfs(v,lasl+1,lasw+w);
}

void solve(){
    Dfs(1,0,0);
    for(int i=1;i<=n;++i) if(ans[i])
        cout<<i<<" ";
}
void init(){
    cin>>n>>m>>l>>s>>t;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
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