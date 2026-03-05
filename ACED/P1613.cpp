#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=100+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;

bool e[maxn][maxn][65];
int d[maxn][maxn];



void solve(){
    for(int l=1;l<64;++l) for(int k=1;k<=n;++k) 
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) 
            if(e[i][k][l-1]&e[k][j][l-1]) 
                e[i][j][l]=1,d[i][j]=1;

    for(int k=1;k<=n;++k) for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    cout<<d[1][n];
}

void init(){
    cin>>n>>m;
    int u,v;
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;++i) 
        cin>>u>>v,e[u][v][0]=1,d[u][v]=1;
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