#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,ll>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
ll wmax,a[maxn];
struct Edge{
    ll v,w,id;
};
vector<Edge>e[maxn];
int siz[maxn],son[maxn],fa[maxn];
int pos[maxn];
struct Info{
    ll lmax,rmax,len,ans;
    Info(ll val=0){
        lmax=rmax=len=ans=val;
    }
};
Info Compress(Info &u,Info &v){
    Info res;
    res.len=u.len+v.len;
    res.ans=max({u.ans,v.ans,u.rmax+v.lmax});
    res.lmax=max(u.lmax,u.len+v.lmax);
    res.rmax=max(v.rmax,v.len+u.rmax);
    return res;
}
Info Rake(Info &u,Info &v){
    Info res;
    res.len=u.len;
    res.ans=max({u.ans,v.ans,u.lmax+v.lmax});
    res.lmax=max(u.lmax,v.lmax);
    res.rmax=max(u.rmax,u.len+v.lmax);
    return res;
}
struct TopTree{
    struct Node{
        int ls,rs,fa;
        Info val;
        bool ty;
        int siz;
    }t[maxn];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define fa(p) t[p].fa
#define val(p) t[p].val
#define siz(p) t[p].siz
#define ty(p) t[p].ty
    int idx,rt;
    int NewNode(bool ty,ll val=0){
        t[++idx]={0,0,0,{val},ty,1};
        return idx;
    }
    void PushUp(int p){
        siz(p)=siz(ls(p))+siz(rs(p));
        val(p)=(ty(p)?Rake:Compress)(val(ls(p)),val(rs(p)));
    }
    int Merge(int u,int v,bool ty){
        int p=NewNode(ty);
        fa(ls(p)=u)=fa(rs(p)=v)=p;
        PushUp(p);
        return p;
    }
    int SubBuild(vector<int>&C,int l,int r,bool ty){
        if(l==r) return C[l];
        int sum=0,now=0;
        for(int i=l;i<=r;++i)
            sum+=siz(C[i]);
        for(int i=l;i<r;++i) if((now+=siz(C[i]))*2>=sum||i==r-1)
            return Merge(SubBuild(C,l,i,ty),SubBuild(C,i+1,r,ty),ty);
    }
    int Build(int p){
        vector<int>H;
        if(p<=n) H.push_back(p);
        for(int u=p;son[u];u=son[u]){
            vector<int>L;
            for(auto[v,w,id]:e[u]) if(v^fa[u]&&v^son[u]) 
                L.push_back(Build(v));
            if(!L.size()) H.push_back(son[u]);
            else H.push_back(Merge(son[u],SubBuild(L,0,L.size()-1,1),1));
        }
        return SubBuild(H,0,H.size()-1,0);
    }
    void Change(int u,ll k){
        val(u)={k};
        while(u=fa(u)) PushUp(u); 
    }
    ll Query(){
        return val(rt).ans;
    }
    void Init(){
        for(int i=1;i<=n;++i)
            NewNode(0,a[i]);
        rt=Build(1);
    }
}t;
void Dfs(int u,int p){
    siz[u]=1,fa[u]=p;
    for(auto[v,w,id]:e[u]) if(v^p)
        Dfs(v,u),pos[id]=v,a[v]=w,siz[u]+=siz[v],siz[v]>siz[son[u]]?son[u]=v:0;
}

void solve(){
    ll lasans=0,u,w;
    while(m--){
        cin>>u>>w;
        u=(u+lasans)%(n-1);
        w=(w+lasans)%wmax;
        t.Change(pos[u+1],w);
        cout<<(lasans=t.Query())<<'\n';
    }
}
void init(){
    cin>>n>>m>>wmax;
    ll u,v,w;
    for(int i=1;i<n;++i)
        cin>>u>>v>>w,e[u].push_back({v,w,i}),e[v].push_back({u,w,i});
    Dfs(1,0);
    t.Init();
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