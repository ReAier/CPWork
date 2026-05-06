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
int a[maxn],w[maxn];
map<int,int> mp;
vector<int>e[maxn],p[maxn];
pii mi[maxn];

void Dfs1(int u,int fa) {
    w[u]=a[u];
    int miv=0,miv2=0,mi2=INF;
    for(int v:e[u]) if(v^fa) {
        Dfs1(v,u);
        if(w[u]>w[v]) 
            w[u]=w[v],miv=v;
    }
    for(int v:e[u]) if(v^fa&&v^miv) {
        if(mi2>w[v])
            mi2=w[v],miv2=v;
    }
    mi[u]={miv,miv2};
}
void Dfs2(int u,int fa,int las) {
    las=min(las,a[u]);
    for(int v:e[u]) if(v^fa) {
        int k=min(las,w[v==mi[u].first?mi[u].second:mi[u].first]);
        p[u].push_back(w[v]);
        p[v].push_back(k);
        Dfs2(v,u,k);
    }
}
stack<pii>st;
void Add(int u,bool b){
    mp[u]++;
    if(b) st.push({u,1});
}
void Del(int u,bool b){
    mp[u]--;
    if(!mp[u]) 
        mp.erase(u);
    if(b) st.push({u,-1});
}
int Query(){
    return (*mp.begin()).first;
}
ll Calc(int u) {
    if(p[u].size()==1) 
        return 0;
    ll ans=0;
    Del(a[u],1);
    for(int v:p[u]) 
        ans+=v,Del(v,1),Add(v+1,1);
    int d=p[u].size()-2;
    while(d--){
        int v=Query();
        ans+=v;
        Del(v,1),Add(v+1,1);
    }
    while(st.size()){
        auto[u,w]=st.top();
        st.pop();
        if(w==1) 
            Del(u,0);
        else Add(u,0);
    }
    return ans;
}

void solve(){
    Dfs1(1,0);
    Dfs2(1,0,INF);
    for(int u=1;u<=n;++u)
        cout<<Calc(u)<<" ";
}
void init(){
    cin>>n;
    w[0]=INF;
    for(int i=1;i<=n;++i) 
        cin>>a[i],mp[a[i]]++;
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