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
int n,m;
vector<pair<int,int>>e[maxn];
int a[maxn];


int d[maxn];
queue<int>q;
bitset<maxn>inq;
void Spfa(int s){
    memset(d,-0x3f,sizeof(d));
    d[s]=0;
    q.push(s);
    inq[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(auto [v,w]:e[u])if(d[u]+w>d[v]){
            d[v]=d[u]+w;
            if(!inq[v]) q.push(v),inq[v]=1;
        }
    }
}

void solve(){
    Spfa(1);
    cout<<d[3*n];
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    int u,v,w;
    for(int i=1;i<=m;++i) {
        cin>>u>>v>>w;
        e[u].push_back({v,0}),e[u+n].push_back({v+n,0}),e[u+2*n].push_back({v+2*n,0});
        if(w==2)e[v].push_back({u,0}),e[v+n].push_back({u+n,0}),e[v+2*n].push_back({u+2*n,0});
    }
    for(int i=1;i<=n;++i) 
        e[i].push_back({i+n,-a[i]}),e[i+n].push_back({i+2*n,a[i]});
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