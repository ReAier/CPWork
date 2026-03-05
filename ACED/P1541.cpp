#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=400+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int dp[5][41][41][41][41];
int a[maxn],b[5];


void solve(){
    int now=0;
    for(int i=1;i<=n;++i) {
            for(int a1=0;a1<=b[1];++a1)for(int a2=0;a2<=b[2];++a2)for(int a3=0;a3<=b[3];++a3)for(int a4=0;a4<=b[4];++a4){
            if(dp[now][a1][a2][a3][a4]<0) continue;
            if(i+a1+a2*2+a3*3+a4*4!=n) continue;
            if(a1>0)
                dp[(now+1)%5][a1-1][a2][a3][a4]=max(dp[now][a1][a2][a3][a4]+a[i+1],dp[(now+1)%5][a1-1][a2][a3][a4]);
            if(a2>0)
                dp[(now+2)%5][a1][a2-1][a3][a4]=max(dp[now][a1][a2][a3][a4]+a[i+2],dp[(now+2)%5][a1][a2-1][a3][a4]);
            if(a3>0)
                dp[(now+3)%5][a1][a2][a3-1][a4]=max(dp[now][a1][a2][a3][a4]+a[i+3],dp[(now+3)%5][a1][a2][a3-1][a4]);
            if(a4>0)
                dp[(now+4)%5][a1][a2][a3][a4-1]=max(dp[now][a1][a2][a3][a4]+a[i+4],dp[(now+4)%5][a1][a2][a3][a4-1]);
        }
        if(i!=n)
            memset(dp[now],-0x3f,sizeof(dp[now]));
        now=(now+1)%5;
    }
    cout<<dp[(now+4)%5][0][0][0][0];
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    int u;
    for(int i=1;i<=m;++i) cin>>u,b[u]++;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][b[1]][b[2]][b[3]][b[4]]=a[1];
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