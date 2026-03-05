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
const double eps=1e-8;
int n,m,k;
int s,t;
vector<pair<int,int>>e[maxn];

priority_queue<pair<int,int>>q;
int d[maxn];
bool vis[maxn];
void Dijstra(int s){
    memset(d,0x3f,sizeof d);
    d[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:e[u]) if(!vis[v.first]&&d[v.first]>d[u]+v.second)
            d[v.first]=d[u]+v.second,q.push({-d[v.first],v.first}); 
    }
}

void solve(){
    Dijstra(s);
    int ans=INF;
    for(int i=0;i<=k;++i)
        ans=min(ans,d[t+n*i]);
    cout<<ans;
}

void init(){
    cin>>n>>m>>k>>s>>t;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        for(int j=0;j<k;++j){
            e[u+j*n].push_back({v+(j+1)*n,0});
            e[v+j*n].push_back({u+(j+1)*n,0});
            e[u+j*n].push_back({v+j*n,w});
            e[v+j*n].push_back({u+j*n,w});
        }
        e[u+n*k].push_back({v+n*k,w});
        e[v+n*k].push_back({u+n*k,w});
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