#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
#define ForE(u) for(int _i=head[u],v=e[_i].v,w=e[_i].w;_i;_i=e[_i].nx,v=e[_i].v,w=e[_i].w)
using namespace std;
const int maxn=1e4+10,INF=1e9,mod=1e9+7;
int n,m;
struct Edge{
    ll u,v,w,nx;
    Edge(){}
    Edge(ll U,ll V,ll W,ll Nx):u(U),v(V),w(W),nx(Nx){}
}e[maxn];
ll head[maxn],midx;
void addedge(int u,int v,ll w=1){
    e[++midx]=Edge(u,v,w,head[u]);
    head[u]=midx;
}
bool inq[maxn];
ll mcnt[maxn],h[maxn];
bool spfa(int s){
    queue<int>q;
    for(int i=0;i<=n;++i) h[i]=INF;
    q.push(s);
    h[s]=0;
    inq[s]=1;
    while (q.size()){
        int u =q.front();
        q.pop();
        inq[u]=0;
        ForE(u){
            if(h[v]>h[u]+w){
                h[v]=h[u]+w;
                mcnt[v]=mcnt[u]+1;
                if(mcnt[v]>n) return 0;
                if(!inq[v]) q.push(v),inq[v]=1;
            }
        }
    }
    return 1;
}

ll d[maxn];
bool vis[maxn];
void dijstra(int s){
    priority_queue<pair<int,int>>q;
    for(int i=0;i<=n;++i) d[i]=INF,vis[i]=0;
    q.push({0,s});
    d[s]=0;
    while(!q.empty()){
        auto u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ForE(u){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!vis[v]) q.push({-d[v],v});
            }
        }
    }
}

void solve(){
    if(!spfa(0)) return printf("-1"),void();
    for(int i=1;i<=midx;++i) e[i].w+=h[e[i].u]-h[e[i].v];
    for(int i=1;i<=n;++i){
        dijstra(i);
        ll ans=0;
        for(ll j=1;j<=n;++j){
            if(d[j]==INF) ans+=(ll)(j*INF);
            else ans+=(ll)(j*(d[j]+h[j]-h[i]));
        }
        cout<<ans<<endl;
    }
}

void init(){
    cin>>n>>m;
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    for(int i=1;i<=n;++i) addedge(0,i,0);
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