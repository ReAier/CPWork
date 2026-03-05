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
const int maxn=1e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int a[maxn];
vector<int>e[maxn];
struct LCA{
    int fa[maxn],top[maxn],siz[maxn],son[maxn],dep[maxn];
    void Dfs1(int u,int fat){
        dep[u]=dep[fat]+1;
        fa[u]=fat,siz[u]=1;
        for(int v:e[u]) if(v!=fat){
            Dfs1(v,u),siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) 
                son[u]=v;
        }
    }
    void Dfs2(int u,int tp){
        top[u]=tp;
        if(!son[u]) return;
        Dfs2(son[u],tp);
        for(int v:e[u]) if(v!=fa[u]&&v!=son[u]) 
            Dfs2(v,v);
    }
    int Lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) 
                swap(u,v);
            u=fa[top[u]];
        }
        return dep[u]<dep[v]?u:v;
    }
    int GetDis(int u,int v){
        int lca=Lca(u,v);
        return dep[u]+dep[v]-2*dep[lca];
    }
    void Init(){
        Dfs1(1,0);
        Dfs2(1,1);
    }
};
struct SegTree{
    int root[maxn],idx;
    struct Node{
        int ls,rs,sum;
    }t[maxn<<5];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define sum(p) t[p].sum
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Change(int &p,int l,int r,int x,int k){
        if(!p) p=++idx;
        if(l==r) return sum(p)+=k,void(); 
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    int Query(int p,int l,int r,int L,int R){
        if(l>R||r<L||!p) return 0;
        if(L<=l&&R>=r) return sum(p);
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    void Change(int u,int x,int k){
        Change(root[u],0,n,x,k);
    }
    int Query(int u,int x){
        return Query(root[u],0,n,0,x);
    }
};
struct CenTree{
    int siz[maxn],mxp[maxn],cen,fa[maxn];
    bitset<maxn>vis;
    LCA lca;
    SegTree t,f;
    int w[maxn];
    void GetCen(int u,int fa,int tot){
        siz[u]=1,mxp[u]=0;
        for(int v:e[u]) if(v!=fa&&!vis[v])
            GetCen(v,u,tot),siz[u]+=siz[v],mxp[u]=max(mxp[u],siz[v]);
        mxp[u]=max(mxp[u],tot-siz[u]);
        if(!cen||mxp[u]<mxp[cen]) cen=u;
    }
    void Build(int u,int tot){
        vis[u]=1;
        for(int v:e[u])if(!vis[v]){
            cen=0;
            tot=siz[v];
            GetCen(v,u,tot);
            fa[cen]=u;
            Build(cen,tot);
        }
    }
    void Change(int u,ll k){
        int now=u;
        while(now){
            t.Change(now,lca.GetDis(u,now),k-w[u]);
            if(fa[now]) f.Change(now,lca.GetDis(u,fa[now]),k-w[u]);
            now=fa[now];
        }
        w[u]=k;
    }
    ll Query(int u,int k){
        ll ans=0,now=u,pre=0;
        while(now){
            int dis=lca.GetDis(now,u);
            if(dis<=k){
                ans+=t.Query(now,k-dis);
                if(pre) ans-=f.Query(pre,k-dis);
            }
            pre=now,now=fa[now];
        }
        return ans;
    }
    void Init(){
        lca.Init();
        GetCen(1,0,n);
        Build(cen,n);
        for(int i=1;i<=n;++i)
            Change(i,a[i]);
    }
}t;


void solve(){
    ll lastans=0,op,x,k;
    while(m--){
        cin>>op>>x>>k;
        x^=lastans,k^=lastans;
        if(op) t.Change(x,k);
        else cout<<(lastans=t.Query(x,k))<<'\n';
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int u,v;
    for(int i=1;i<n;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    t.Init();
}
int main(){
#ifdef OPEN_FILE
    freopen("P6329_1.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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