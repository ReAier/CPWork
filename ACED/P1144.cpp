#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=100003;
const double eps=1e-8;
int n,m;
vector<int>e[maxn];

int d[maxn],cnt[maxn];
bool vis[maxn];
queue<int>q;
void Bfs(int s){
    q.push(s);
    memset(d,0x3f,sizeof d);
    d[s]=0;
    cnt[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:e[u]) if(d[u]+1<d[v]) {
            cnt[v]=cnt[u];
            d[v]=d[u]+1;
            q.push(v);
        }else if(d[u]+1==d[v]){
            cnt[v]+=cnt[u];
            cnt[v]%=mod;
            q.push(v);
        }
    }
}

void solve(){
    Bfs(1);
    for(int i=1;i<=n;++i) cout<<cnt[i]<<"\n";
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