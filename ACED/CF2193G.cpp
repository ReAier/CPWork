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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
vector<int>e[maxn];
int tim,a[maxn];
void Dfs(int u,int fa){
    a[++tim]=u;
    for(int v:e[u]) if(v!=fa)
        Dfs(v,u);
}
void solve(){
    Dfs(1,0);
    int op;
    for(int i=1;i+1<=n;i+=2){
        cout<<"? "<<a[i]<<" "<<a[i+1]<<endl;
        cin>>op;
        if(op){
            cout<<"? "<<a[i]<<" "<<a[i]<<endl;
            cin>>op;
            if(op) cout<<"! "<<a[i]<<endl;
            else cout<<"! "<<a[i+1]<<endl;
            return;
        }
    }
    cout<<"! "<<a[n]<<endl;
}
void init(){
    cin>>n;
    tim=0;
    for(int i=1;i<=n;++i)
        e[i].clear();
    int u,v;
    for(int i=1;i<n;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
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