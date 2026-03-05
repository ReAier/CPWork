#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;

const int maxn=50000+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m,B;
ll a[maxn],b[maxn],K[maxn];
vector<ll>e[maxn];

int dep[maxn],fa[maxn],siz[maxn],son[maxn];
void Dfs1(ll u,ll fat){
    dep[u]=dep[fa[u]=fat]+1;
    siz[u]=1;
    for(ll v:e[u]) if(v!=fat) {
        Dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
ll id[maxn],idx,dfn[maxn],top[maxn];
void Dfs2(ll u,ll tp){
    top[u]=tp;
    id[dfn[u]=++idx]=u;
    if(!son[u]) return;
    Dfs2(son[u],tp);
    for(ll v:e[u]) if(v!=fa[u]&&v!=son[u]) 
        Dfs2(v,v);
}
ll getk(ll u,ll k){
    ll dpv=dep[u]-k;
    if(dpv<1) return 0;
    while(dep[top[u]]>dpv) 
        u=fa[top[u]];
    return id[dfn[u]-dep[u]+dpv];
}
ll lca(ll u,ll v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])
            swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
ll c[maxn][250];
void Dfs3(ll u){
    for(ll i=1;i<=B;++i)
        c[u][i]=c[getk(u,i)][i]+a[u];
    for(ll v:e[u]) if(v!=fa[u]) Dfs3(v);
}
ll aget(ll u,ll v,ll k){
    ll ans=0,lc=lca(u,v);
    while(dep[u]>=dep[lc]) ans+=a[u],u=getk(u,k);
    while(dep[v]>dep[lc]) ans+=a[v],v=getk(v,k);
    return ans;
}

void solve(){
    Dfs1(1,0);
    Dfs2(1,1);
    Dfs3(1);
    ll u,v,k;
    for(ll i=1;i<n;++i){
        u=b[i],v=b[i+1],k=K[i];
        if(k<=B){
            ll ans=c[u][k]+c[v][k],l=lca(u,v),lu=dep[u]-dep[l],lv=dep[v]-dep[l];
            ans-=c[getk(l,k-(lu%k))][k]+c[getk(l,k-(lv%k))][k];
            if(!(lu%k)) ans-=a[l];
            cout<<ans<<'\n';
        }else
            cout<<aget(u,v,k)<<'\n';
    }
}


void init(){
    cin>>n;
    B=sqrt(n);
    for(ll i=1;i<=n;++i)
        cin>>a[i];
    ll u,v;
    for(ll i=1;i<n;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    for(ll i=1;i<=n;++i) cin>>b[i];
    for(ll i=1;i<n;++i) cin>>K[i];
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif,
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    // ios::sync_with_stdio(false),cin.tie(nullptr)cout.tie(nullptr);
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