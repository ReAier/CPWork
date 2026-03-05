#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
// #define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const int maxn=1.5e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
bitset<30> b1[200],b2[200],f1[200],f2[200];
int dp[maxn];
int t[maxn];


priority_queue<pair<int,int>>q;
bool vis[maxn];
void Dijstra(int s){
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second,v;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        bitset<30> bi(u),nbi;
        for(int j=1;j<=m;++j) if((((~bi)&b1[j])==b1[j])&&(((~bi)&b2[j]).none())) {
            nbi=bi;
            nbi|=f1[j];
            nbi&=~f2[j];
            v=nbi.to_ulong();
            if(dp[v]>dp[u]+t[j]) {
                dp[v]=dp[u]+t[j];
                q.push({-dp[v],v});
            }
        }
    }
}

void solve(){
    Dijstra(0);
    if(dp[(1<<n)-1]==INF) cout<<0;
    else cout<<dp[(1<<n)-1];
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>t[i];
        getchar();
        char ch;
        for(int j=1;j<=n;++j){
            ch=getchar();
            if(ch=='+')
                b1[i][j-1]=1;
            else if(ch=='-')
                b2[i][j-1]=1;
        }
        getchar();
        for(int j=1;j<=n;++j){
            ch=getchar();
            if(ch=='-')
                f1[i][j-1]=1;
            else if(ch=='+')
                f2[i][j-1]=1;
        }
    }
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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
