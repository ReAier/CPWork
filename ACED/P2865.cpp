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

int d1[maxn],d2[maxn];
priority_queue<pair<int,int>>q;
void Dijstra(int s){
    for(int i=1;i<=n;++i) d1[i]=d2[i]=INF;
    d1[s]=0;
    q.push({0,s});
    while(!q.empty()){
        auto [du,u]=q.top();q.pop();
        du=-du;
        if(du>d2[u]) continue;
        for(auto [v,w]:e[u]){
            if(du+w<d1[v]){
                d2[v]=d1[v];
                d1[v]=du+w;
                q.push({-d1[v],v});
            }else if(du+w<d2[v]&&du+w>d1[v]){
                d2[v]=du+w;
                q.push({-d2[v],v});
            }
        }
    }
}


void solve(){
    Dijstra(1);
    cout<<d2[n];
}

void init(){
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;++i) 
        cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
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