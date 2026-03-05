#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;

vector<pair<int,double>>e[maxn];


double dis[maxn];
int ind1[maxn],ind2[maxn];
void solve(){
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto [v,w]:e[u]){
            dis[v]+=(dis[u]+w)/ind2[v];
            if(!(--ind1[v])) q.push(v);
        }
    }
    printf("%.2f",dis[1]);
}

void init(){
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;++i) 
        cin>>u>>v>>w,e[v].push_back({u,w}),ind2[u]++,ind1[u]++;
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