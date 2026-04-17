#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
vector<pii>e[maxn];
ll ans,cnt[maxn],sum,tot,siz[maxn];

void Change(int x,int w){
    sum+=w-cnt[x];
    cnt[x]=w;
}
void Dfs(int u,int fa){
    siz[u]=1,tot++,ans+=sum;
    for(auto[v,w]:e[u]) if(v^fa){
        int lasw=cnt[w];
        Change(w,tot);
        Dfs(v,u);
        siz[u]+=siz[v];
        Change(w,lasw+siz[v]);
    }
}

void solve(){
    Dfs(1,0);
    cout<<ans*2<<'\n';
}
void init(){
    cin>>n;
    int u,v,w;
    for(int i=1;i<n;++i)
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