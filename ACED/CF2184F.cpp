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
vector<int>e[maxn];
struct Info{
    bool val[3];
    bool& operator[](int i){
        return val[i];
    }
    Info operator+(Info x){
        Info ans={0,0,0};
        for(int i=0;i<3;++i) for(int j=0;j<3;++j)
            if(val[i]&x[j])
                ans[(i+j)%3]=1;
        return ans;
    }
}dp[maxn];
Info I={0,0,0};
void Dfs(int u,int fa){
    if(e[u].size()>1||u==1) dp[u][0]=1;
    for(int v:e[u]) if(v!=fa) {
        Dfs(v,u);
        dp[u]=dp[u]+dp[v];
    }
    dp[u][1]=1;
}

void solve(){
    Dfs(1,0);
    if(dp[1][0])
        cout<<"YES\n";
    else cout<<"NO\n";
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        dp[i]=I,e[i].clear();
    int u,v;
    for(int i=1;i<n;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
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