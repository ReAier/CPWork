#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m;
ll a[3],amin;
vector<pair<ll,ll>>e[maxn];

ll d[maxn];
bool vis[maxn];
priority_queue<pair<int,int>>q;
void Dijstra(int s){
    memset(d,0x3f,sizeof(d));
    q.push({0,s});
    d[s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        vis[u]=1;
        for(auto [v,w]:e[u]) if(d[v]>d[u]+w){
            d[v]=d[u]+w;
            q.push({-d[v],v});
        }
    }
}

void solve(){
    Dijstra(0);
    ll ans=0;
    for(int i=0;i<amin;++i) if(n>d[i]) 
        ans+=((n-d[i]-1)/amin)+1;
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=0;i<3;++i) cin>>a[i];
    amin=min(a[0],min(a[1],a[2]));
    for(int i=0;i<amin;++i) for(int j=0;j<3;++j) e[i].push_back({(i+a[j])%amin,a[j]});
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