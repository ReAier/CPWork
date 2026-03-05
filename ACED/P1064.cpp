#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn][2];
int W[maxn],P[maxn];
bool nz[maxn];
vector<vector<pair<int,int>>>f;

ll dp[150][maxn];

void solve(){
    for(int i=1;i<=f.size();++i)
        for(auto [w,p]:f[i-1])
            for(int j=n;j>=w;--j)
                dp[i][j]=max(dp[i][j],dp[i-1][j-w]+p);
    ll ans=0;
    for(int i=0;i<=n;++i) ans=max(ans,dp[f.size()][i]);
    cout<<ans*10;
}

void init(){
    cin>>n>>m;
    n/=10;
    for(int i=1;i<=m;++i){
        int q;
        cin>>W[i]>>P[i]>>q;
        W[i]/=10;
        P[i]*=W[i];
        if(q) a[q][bool(a[q][0])]=i,nz[i]=1;
    }
    for(int i=1;i<=m;++i) if(!nz[i]){
        f.push_back({{0,0}});
        f.back().push_back({W[i],P[i]});
        if(a[i][0])
            f.back().push_back({W[a[i][0]]+W[i],P[a[i][0]]+P[i]});
        if(a[i][1]){
            f.back().push_back({W[a[i][1]]+W[i],P[a[i][1]]+P[i]});
            f.back().push_back({W[a[i][1]]+W[a[i][0]]+W[i],P[a[i][1]]+P[a[i][0]]+P[i]});
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