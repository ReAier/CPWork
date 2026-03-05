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

queue<int>q;
bool inq[maxn];
int d[maxn],mcnt[maxn];
bool Spfa(int s){
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    q.push(s);
    inq[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=0;
        for(auto [v,w]:e[u]) if(d[v]>d[u]+w) {
            d[v]=d[u]+w;
            if((mcnt[v]=mcnt[u]+1)>n) return 0;
            if(!inq[v]) q.push(v),inq[v]=1;
        }
    }
    return 1;
}

void solve(){
    if(Spfa(0)) for(int i=1;i<=n;++i) cout<<d[i]<<" ";
    else cout<<"NO";
}

void init(){
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;++i) cin>>u>>v>>w,e[v].push_back({u,w});
    for(int i=1;i<=n;++i) e[0].push_back({i,0});
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