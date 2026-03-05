#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=200+10,INF=1e9+10,mod=1e9+7;
int n,m;
vector<int>e[maxn];
int d[maxn];

bool vis[maxn];
queue<int>q,ans;

void topo(int s){
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ans.push(u);
        for(int v:e[u]) if(!(--d[v])&&!vis[v]) q.push(v);
    }
}

void solve(){
    for(int i=1;i<=n;++i) if(!d[i]) 
        topo(i);
    while(ans.size()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
}
void init(){
    cin>>n;
    int v;
    for(int i=1;i<=n;++i){
        cin>>v;
        while(v){
            e[i].push_back(v);
            d[v]++;
            cin>>v;
        }
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