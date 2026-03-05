#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m,H;
pair<int,int> a[maxn];
int mp[maxn];
vector<pair<int,int>>e[maxn];

int d[maxn];
bool vis[maxn];
priority_queue<pair<int,int>>q;
bool Dijstra(int k){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[1]=0;
    q.push({0,1});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(u==n) return 1;
        if(vis[u]||mp[u]>k) continue;
        vis[u]=1;
        for(auto [v,w]:e[u]){
            if(d[u]+w<=min(H,d[v])){
                d[v]=d[u]+w;
                q.push({-d[v],v});
            }
        }
    }
    return 0;
}
void solve(){
    int l=max(mp[n],mp[1]),r=n+1;
    while(l<r){
        int mid=l+r>>1;
        if(Dijstra(mid)) r=mid;
        else l=mid+1;
    }
    if(l<=n) 
        cout<<a[l].first;
    else cout<<"AFK";
}

void init(){
    cin>>n>>m>>H;
    for(int i=1;i<=n;++i)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
        mp[a[i].second]=i;
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