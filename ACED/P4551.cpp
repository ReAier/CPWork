#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
vector<pair<int,int>>e[maxn];
int dep[maxn];
void dfs(int u,int fa){
    for(auto v:e[u]) if(v.first!=fa) 
        dep[v.first]=dep[u]^v.second,dfs(v.first,u);
}

int son[maxn][2],idx=1;

bool getw(int x,int i){
    return x&(1<<i);
}

void addnum(int x){
    int idnow=1;
    for(int i=30;i>=0;--i){
        if(!son[idnow][getw(x,i)])son[idnow][getw(x,i)]=++idx;
        idnow=son[idnow][getw(x,i)]; 
    }
}

int query(int x){
    int idnow=1,ans=0;
    for(int i=30;i>=0;--i){
        if(son[idnow][getw(x,i)^1]) idnow=son[idnow][getw(x,i)^1],ans+=(1<<i);
        else idnow=son[idnow][getw(x,i)]; 
    }
    return ans;
}

void solve(){
    for(int i=1;i<=n;++i) addnum(dep[i]);
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,query(dep[i]));
    cout<<ans;
}

void init(){
    cin>>n;
    int u,v,w;
    for(int i=1;i<n;++i){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
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