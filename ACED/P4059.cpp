#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m,A,B;
string s,t;
int mp[256];
int d[5][5],dp[maxn][maxn][3];
//0 
//1 _
//2  _


void solve(){
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
        dp[i][j][0]=max({dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j-1][2]}) 
            +d[mp[s[i-1]]][mp[t[j-1]]];
        dp[i][j][1]=max({dp[i-1][j][0]-A,dp[i-1][j][1]-B,dp[i-1][j][2]-A});
        dp[i][j][2]=max({dp[i][j-1][0]-A,dp[i][j-1][2]-B,dp[i][j-1][1]-A});
    }
    cout<<max({dp[n][m][0],dp[n][m][1],dp[n][m][2]});
}
void init(){
    cin>>s>>t;
    n=s.size(),m=t.size();
    for(int i=1;i<=4;++i) for(int j=1;j<=4;++j) 
        cin>>d[i][j];
    cin>>A>>B;
    mp['A']=1,mp['T']=2,mp['G']=3,mp['C']=4;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;++i) dp[i][0][1]=-A-B*(i-1);
    for(int i=1;i<=m;++i) dp[0][i][2]=-A-B*(i-1);
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