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
int n,m,sx,sy;
char mp[maxn][maxn];
bool vis[maxn][maxn];

void Dfs(int x,int y){
    if(vis[x][y]) return;
    vis[x][y]=1;
    if(x==1) return;
    if(y>1&&mp[x-1][y-1]=='.')
        Dfs(x-1,y-1);
    if(y<n&&mp[x-1][y+1]=='.')
        Dfs(x-1,y+1);
    if(mp[x-1][y]=='.')
        Dfs(x-1,y);
}
void solve(){
    Dfs(sx,sy);
    for(int i=1;i<=n;++i) cout<<vis[1][i];
    cout<<'\n';
}
void init(){
    cin>>n>>m;
    sx=n,sy=m;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
        vis[i][j]=0;
    for(int i=1;i<=n;++i)
        scanf("%s",mp[i]+1);
    for(int i=1;i<=sy;++i){
        int flg=1;
        for(int j=n;j>=n-sy+i+1;--j)
            if(mp[j][i]=='#') flg=0;
        if(flg) for(int j=n-sy+i;j>=1;--j)
            mp[j][i]='.';
    }
    for(int i=sy+1;i<=n;++i){
        int flg=1;
        for(int j=n;j>=n+sy-i+1;--j)
            if(mp[j][i]=='#') flg=0;
        if(flg) for(int j=n+sy-i;j>=1;--j)  
            mp[j][i]='.';
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