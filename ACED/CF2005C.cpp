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
const int maxn=1e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int dp[6][2];
string s[maxn];
map<char,int> mp;

void solve(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=5;++j) 
            dp[j][1]=dp[j][0]=max(dp[j][0],dp[j][1]);
        for(char ch:s[i]){
            int k=mp[ch];
            if(k){
                if(k!=1) dp[k][1]=max(dp[k][1],dp[k-1][1]+2);
                else dp[1][1]=max(dp[1][1],dp[5][1]+2);
                for(int j=1;j<=5;++j)
                    --dp[j][1];
            }
        }
    }
    cout<<max(dp[5][0],dp[5][1])<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    memset(dp,-0x3f,sizeof(dp));
    dp[5][0]=0;
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
    mp['n']=1,mp['a']=2,mp['r']=3,mp['e']=4,mp['k']=5;
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