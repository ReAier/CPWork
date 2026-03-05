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
int low[maxn];
char mp[maxn][maxn];
bool dp[maxn][maxn];

void solve(){
    for(int i=n-1;i>=1;--i){
        for(int j=1;j<=n;++j){
            if(dp[i+1][j-1]|dp[i+1][j]|dp[i+1][j+1]){
                if(mp[i][j]=='.')   
                    dp[i][j]=1;
                else if(low[j]==i) for(int k=i;k>=1;--k)
                    dp[k][j]=1; 
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<dp[1][i];
    cout<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=0;i<=n+2;++i) for(int j=0;j<=n+2;++j)
        dp[i][j]=0;
    for(int i=1;i<=n;++i) low[i]=0;
    for(int i=1;i<=n;++i){
        scanf("%s",mp[i]+1);
        for(int j=1;j<=n;++j) if(mp[i][j]=='#')
            low[j]=i;
    }
    dp[n][m]=1;
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