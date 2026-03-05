#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
double x[20],y[20];
double vis[(1<<16)+10][16];

double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void printbit(int a){
    for(int i=1;i<=n;++i)
        cout<<bool(a&(1<<(i-1)));
}

double dfs(int p,int a){
    if(vis[p][a]!=INF) return vis[p][a];
    if(p==((1<<(n))-1)) return vis[p][a]=0;
    for(int i=1;i<=n;++i){
        if(p&(1<<(i-1))) continue;
        vis[p][a]=min(vis[p][a],dfs(p|(1<<(i-1)),i)+distance(x[a],y[a],x[i],y[i]));
    }
    // printbit(p);
    // cout<<" "<<a<<" "<<vis[p][a]<<endl;
    return vis[p][a];
}

void solve(){
    for(int i=0;i<=(1<<(n+1));++i) for(int j=0;j<=n;++j)vis[i][j]=INF;
    double ans=INF;
    for(int i=1;i<=n;++i)
        ans=min(ans,dfs(1<<(i-1),i)+distance(0,0,x[i],y[i]));
    printf("%.2f",ans);
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}