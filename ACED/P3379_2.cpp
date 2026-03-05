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
int n,m,s;
vector<int>e[maxn];
struct que{
    int v,i;
};
vector<que>q[maxn];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int rt[maxn];
int find(int x){
    if(rt[x]==x) return x;
    return rt[x]=find(rt[x]);
}
bitset<maxn>vis;
int ans[maxn];
void tarjan(int u){
    vis[u]=1;
    for(int v:e[u]){
        if(vis[v]) continue;
        tarjan(v);
        rt[v]=u;
    }
    for(auto v:q[u]){
        if(vis[v.v]) ans[v.i]=find(v.v);
    }
}

void solve(){
    tarjan(s);
    for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
}

void init(){
    n=read();
    m=read();
    s=read();
    for(int i=1;i<n;++i) {
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        q[u].push_back({v,i});
        q[v].push_back({u,i});
    }
    for(int i=1;i<=n;++i) rt[i]=i;
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