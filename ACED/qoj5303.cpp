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
const int maxn=3e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int p[maxn][20],pre[maxn][maxn],suf[maxn][maxn],S,sum;

void solve() {
    if(S<=m) return cout<<sum<<'\n',void();
    for(int i=1;i<=n;++i) for(int j=0;j<=m;++j) {
        pre[i][j]=pre[i-1][j];
        if(j>=p[i][0]) pre[i][j]=max(pre[i][j],pre[i-1][j-p[i][0]]+p[i][p[i][0]]);
    }
    for(int i=n;i>=1;--i) for(int j=0;j<=m;++j) {
        suf[i][j]=suf[i+1][j];
        if(j>=p[i][0]) suf[i][j]=max(suf[i][j],suf[i+1][j-p[i][0]]+p[i][p[i][0]]);
    }
    int ans=pre[n][m];
    for(int i=1;i<=n;++i) for(int j=0;j<=m;++j) {
        ans=max(ans,pre[i-1][j]+suf[i+1][m-j]);
        for(int k=1;k<=min(p[i][0],j);++k) 
            ans=max(ans,pre[i-1][j-k]+p[i][k]+suf[i+1][m-j]);
    }
    cout<<ans<<'\n';
}
void init() {
    memset(pre,-0x3f,sizeof(pre));
    memset(suf,-0x3f,sizeof(suf));
    cin>>n>>m;
    for(int i=1;i<=n;++i) {
        cin>>p[i][0];
        for(int j=1;j<=p[i][0];++j)
            cin>>p[i][j];
        S+=p[i][0],sum+=p[i][p[i][0]];
    }
    pre[0][0]=suf[n+1][0]=0;
}
int main() {
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
    // while(cin>>n) {
    while(T--) {
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}