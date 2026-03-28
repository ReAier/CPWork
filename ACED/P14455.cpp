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
const int maxn=2e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int a[maxn][maxn],lca[maxn][maxn],siz[maxn],fa[maxn];



void solve(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) if(lca[i][j]==j&&i!=j){
            if(!fa[i]||siz[fa[i]]>siz[j])
                fa[i]=j;
        }
    }
    for(int i=2;i<=n;++i)
        cout<<fa[i]<<" "<<i<<'\n';
    
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i) 
        for(int j=i;j<=n;++j) 
            cin>>a[i][j],a[j][i]=a[i][j];
    for(int i=1;i<=n;++i)   
        for(int j=1;j<=n;++j) 
            lca[i][j]=a[i][j]^a[1][i]^a[1][j];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
        siz[i]+=lca[i][j]==i;
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