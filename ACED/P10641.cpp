#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m;
vector<ll>e[maxn];
ll fa[maxn],a[maxn],idx,siz[maxn],b[maxn],pos[maxn];
ll rt;

struct SegTree{
    struct Node{
        ll val,tag;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define val(p) t[p].val
#define tag(p) t[p].tag
    void AddTag(ll p,ll k){
        if(!p) return;
        val(p)+=k;
        tag(p)+=k;
    }
    void PushDown(ll p){
        if(!tag(p)) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)=0;

    }
    void PushUp(ll p){
        val(p)=max(val(ls(p)),val(rs(p)));
    }
    void Add(ll p,ll l,ll r,ll L,ll R,ll k){
        if(r<L||l>R) return;
        if(L<=l&&R>=r) 
            return AddTag(p,k);
        PushDown(p);
        ll mid=l+r>>1;
        Add(ls(p),l,mid,L,R,k);
        Add(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    pair<ll,ll> Query(ll p,ll l,ll r){
        if(l==r) return {l,val(p)};
        PushDown(p);
        ll mid=l+r>>1;
        pair<ll,ll>res;
        if(val(ls(p))==val(p)) res=Query(ls(p),l,mid);
        else res=Query(rs(p),mid+1,r);
        PushUp(p);
        return res;
    }
    void Build(ll p,ll l,ll r){
        if(l==r) return val(p)=a[b[l]],void();
        ll mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Init(){Build(1,1,idx);}
    void Add(ll l,ll r,ll k){return Add(1,1,idx,l,r,k);}
    pair<ll,ll> Query(){
        return Query(1,1,idx);
    }
}t;

void Dfs(ll u,ll las){
    pos[u]=idx+1; 
    for(ll v:e[u]) Dfs(v,las+a[u]),siz[u]+=siz[v];
    if(e[u].empty()) a[u]+=las,siz[u]=1,++idx,b[idx]=u;
}

void Change(ll u){
    while(u){
        if(!a[u]) return;
        t.Add(pos[u],pos[u]+siz[u]-1,-a[u]);
        a[u]=0;
        u=fa[u];
    }
}

void solve(){
    ll ans=0;
    Dfs(rt,0);
    t.Init();
    while(m--){
        auto [u,w]=t.Query();
        Change(b[u]);
        ans+=w;
    }
    cout<<ans;
}

ll d[maxn];
void init(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        cin>>a[i];
    ll u,v;
    for(ll i=1;i<n;++i)
        cin>>u>>v,e[u].push_back(v),d[v]++,fa[v]=u;
    for(ll i=1;i<=n;++i) if(!d[i]) 
        rt=i;
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