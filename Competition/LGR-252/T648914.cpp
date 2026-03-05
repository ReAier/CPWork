#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m,K;
vector<int>e[maxn];
ll s1,t1,s2,t2;

bool vis[maxn];
int d[maxn];
ll Bfs(int s,int t){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:e[u]) if(!vis[v]) 
            q.push(v),d[v]=d[u]+1;
    }
    return d[t];
}


void solve(){
    ll T=Bfs(s1,t1)+Bfs(s2,t2);
    if(T>=INF) return printf("-1\n"),void();
    if(!T) return printf("0\n"),void();
    double mo=K%T,ch=K/T;
    double ans=(T-mo)*(1/(ch+1))+mo*(1/(ch+2));
    printf("%.12f\n",ans);
}

void init(){
    scanf("%lld%lld%lld",&n,&m,&K);
    for(int i=1;i<=n;++i) e[i].clear();
    ll u,v;
    for(int i=1;i<=m;++i) {
        scanf("%lld%lld",&u,&v);
        if(u!=v)
            e[u].push_back(v),e[v].push_back(u);
    }
    scanf("%lld%lld%lld%lld",&s1,&t1,&s2,&t2);
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
    cin>>T;
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