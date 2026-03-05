//一遍过的树刨，实力
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10;
ll n,m,rt,mod;
ll w[maxn],a[maxn],son[maxn],siz[maxn],dep[maxn],fa[maxn],top[maxn],idx,id[maxn];
vector<int>e[maxn];

void dfs1(int u,int fat){
    siz[u]=1;
    fa[u]=fat;
    dep[u]=dep[fat]+1;
    for(int v:e[u]){
        if(v==fat) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int to){
    top[u]=to;
    w[id[u]=++idx]=a[u];
    if(!son[u]) return;
    dfs2(son[u],to);
    for(int v:e[u]){
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
ll sum[maxn<<2],tag[maxn<<2],len[maxn<<2];
void addtag(int p,int k){
    sum[p]+=len[p]*k;
    sum[p]%=mod;
    tag[p]+=k;
    tag[p]%=mod;
}
void push_up(int p){
    sum[p]=(sum[p<<1]+sum[p<<1|1])%mod;
}
void push_down(int p){
    if(!tag[p]) return;
    addtag(p<<1,tag[p]);
    addtag(p<<1|1,tag[p]);
    tag[p]=0;
}
void bulid(int p,int l,int r){
    len[p]=r-l+1;
    if(l==r) return sum[p]=w[l]%mod,void();
    int mid=(l+r)>>1;
    bulid(p<<1,l,mid);
    bulid(p<<1|1,mid+1,r);
    push_up(p);
}
void Change(int p,int l,int r,int L,int R,int k){
    if(l>R||r<L) return;
    if(l>=L&&r<=R) return addtag(p,k);
    push_down(p);
    int mid=(l+r)>>1;
    Change(p<<1,l,mid,L,R,k);
    Change(p<<1|1,mid+1,r,L,R,k);
    push_up(p);
}
ll Query(int p,int l,int r,int L,int R){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return sum[p]%mod;
    push_down(p);
    int mid=(l+r)>>1;
    ll ans=0;
    ans+=Query(p<<1,l,mid,L,R);
    ans+=Query(p<<1|1,mid+1,r,L,R);
    push_up(p);
    return ans%mod;
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
void Change(int u,int v,int k){
    k%=mod;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        Change(1,1,n,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(id[v]<id[u]) swap(u,v);
    Change(1,1,n,id[u],id[v],k);
}
void Change(int u,int k){
    Change(1,1,n,id[u],id[u]+siz[u]-1,k%mod);
}
ll Query(int u,int v){
    ll ans=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        ans+=Query(1,1,n,id[top[u]],id[u]);
        ans%=mod;
        u=fa[top[u]];
    }
    if(id[v]<id[u]) swap(u,v);
    return (ans+Query(1,1,n,id[u],id[v]))%mod;
}
ll Query(int u){
    return Query(1,1,n,id[u],id[u]+siz[u]-1);
}

void solve(){
    dfs1(rt,0);
    dfs2(rt,rt);
    bulid(1,1,n);
    int opt,x,y,z;
    while(m--){
        cin>>opt>>x;
        switch(opt){
            case 1:
            cin>>y>>z;
            Change(x,y,z);
            break;
            case 2:
            cin>>z;
            printf("%d\n",Query(x,z));
            break;
            case 3:
            cin>>z;
            Change(x,z);
            break;
            case 4:
            printf("%d\n",Query(x));
            break;
        }
    }
}

void init(){
    cin>>n>>m>>rt>>mod;
    for(int i=1;i<=n;++i) cin>>a[i];
    int u,v;
    for(int i=1;i<n;++i) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
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