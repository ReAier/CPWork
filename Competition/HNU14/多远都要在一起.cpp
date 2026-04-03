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
int ind[maxn],id[maxn],len,rt[maxn];
bool isd[maxn];
int dep[maxn],fa[maxn],son[maxn],siz[maxn],top[maxn];
void Dfs1(int u,int f,int rot){
    rt[u]=rot;
    dep[u]=dep[fa[u]=f]+(siz[u]=1);
    for(int v:e[u]) if(v!=f&&!isd[v]){
        Dfs1(v,u,rot);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
void Dfs2(int u,int tp){
    top[u]=tp;
    if(!son[u]) return;
    Dfs2(son[u],tp);
    for(int v:e[u]) if(v!=fa[u]&&v!=son[u]&&!isd[v])
        Dfs2(v,v);
}
int GetLCA(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])
            swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]>dep[v]?v:u;
}
void DfsLoop(int u,int las){
    if(id[u]) return;
    id[u]=++len;
    for(int v:e[u]) if(isd[v])
        DfsLoop(v,u);
}
bool Query(int u,int v,int w){
    if(rt[u]==rt[v]){
        int lca=GetLCA(u,v);
        int d=dep[u]+dep[v]-dep[lca]*2;
        if(w>=d&&((w-d)&1)==0) 
            return 1;
        if(len&1&&w>=len+dep[u]+dep[v])
            return 1;
    }else{
        int dl=abs(id[rt[u]]-id[rt[v]]);
        dl=min(dl,len-dl);
        int d=dep[u]+dep[v]+dl;
        if(w>=d&&((w-d)&1)==0) 
            return 1;
        if(len&1&&w>=d+len-2*dl) 
            return 1;
    }
    return 0;
}

void solve(){
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        if(Query(u,v,w))
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}
queue<int>q;
void init(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u),ind[u]++,ind[v]++;
    memset(isd,1,sizeof(isd));
    for(int i=1;i<=n;++i) if(ind[i]==1)
        q.push(i);
    while(q.size()){
        auto u=q.front();q.pop();
        isd[u]=0;
        for(int v:e[u]) if(--ind[v]==1)
            q.push(v);
    }
    dep[0]=-1;
    for(int i=1;i<=n;++i) if(isd[i])
        Dfs1(i,0,i),Dfs2(i,i),u=i;
    DfsLoop(u,0);
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