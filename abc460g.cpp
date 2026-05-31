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
mt19937_64 mt(1145);
int n,m;
int a[maxn],c[maxn];
vector<int>e[maxn];
int siz[maxn],son[maxn],fa[maxn];
struct Info{
    ll all[2],au[2],av[2],val,c;
    Info(ll val=0,int c=0):val(val),c(c){
        all[c^1]=au[c^1]=av[c^1]=0;
        all[c]=1,all[c^1]=0;
        au[c]=av[c]=val;
    }
};
Info Compress(const Info &u,const Info &v){
    Info res;
    res.val=u.val,res.c=u.c;
    for(int c=0;c<=1;++c) {
        res.all[c]=u.all[c]&v.all[c];
        res.au[c]=u.au[c]+(u.all[c]?v.au[c]:0);
        res.av[c]=v.av[c]+(v.all[c]?u.av[c]:0);
    }
    return res;
}
Info Rake(const Info &u,const Info &v){
    Info res;
    res.val=u.val,res.c=u.c;
    for(int c=0;c<=1;++c) {
        res.all[c]=u.all[c];
        res.au[c]=u.au[c]+v.au[c];
        res.av[c]=u.av[c]+(u.all[c]?v.au[c]:0);
    }
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
    int NewNode(bool ty,int val=0,bool c=0){
        t[++idx]={0,0,0,{val,c},ty,1};
        return idx;
    }
    void PushUp(int p){
        val(p)=(ty(p)?Rake:Compress)(val(ls(p)),val(rs(p)));
    }
    int Merge(int u,int v,bool ty){
        int p=NewNode(ty);
        fa(ls(p)=u)=fa(rs(p)=v)=p;
        siz(p)=siz(ls(p))+siz(rs(p));
        PushUp(p);
        return p;
    }
    int SubBuild(vector<int>&C,int l,int r,bool ty){
        if(l==r) return C[l];
        int sum=0,now=0;
        for(int i=l;i<=r;++i)
            sum+=siz(C[i]);
        for(int i=l;i<r-1;++i) if((now+=siz(C[i]))*2>=sum) 
            return Merge(SubBuild(C,l,i,ty),SubBuild(C,i+1,r,ty),ty);
        return Merge(SubBuild(C,l,r-1,ty),SubBuild(C,r,r,ty),ty);
    }
    int Build(int p){
        vector<int>H;
        for(int u=p;u;u=son[u]){
            vector<int>L;
            for(int v:e[u]) if(v^fa[u]&&v^son[u]) 
                L.push_back(Build(v));
            if(!L.size()) H.push_back(u);
            else H.push_back(Merge(u,SubBuild(L,0,L.size()-1,1),1));
        }
        return SubBuild(H,0,H.size()-1,0);
    }
    void Change(int u,int k,int co){
        a[u]+=k,c[u]^=co;
        val(u)={a[u],c[u]};
        while(u=fa(u)) PushUp(u);
    }
    ll Query(int u){
        ll ru=1,rv=1,ans=val(u).val,co=val(u).c,cur=u;
        while(u=fa(u)) {
            if(cur==ls(u)) {
                if(ty(u)) {
                    ans+=ru*val(rs(u)).au[co];
                }else {
                    ans+=rv*val(rs(u)).au[co];
                    rv&=val(rs(u)).all[co];
                }
            }else {
                if(ty(u)) {
                    ans+=ru*val(ls(u)).au[co];
                    rv&=val(ls(u)).all[co];
                }else {
                    ans+=ru*val(ls(u)).av[co];
                    ru*=val(ls(u)).all[co];
                }
            }
            cur=u;
        }
        return ans;
    }
    void Init(){
        for(int i=1;i<=n;++i) 
            NewNode(0,a[i],c[i]);
        rt=Build(1);
    }
}t;
void Dfs(int u,int p){
    siz[u]=1,fa[u]=p;
    for(int v:e[u]) if(v^p)
        Dfs(v,u),siz[u]+=siz[v],siz[v]>siz[son[u]]?son[u]=v:0;
}

void solve() {
    int opt,u,x;
    while(m--) {
        cin>>opt>>u;
        if(opt==2) {
            cin>>x;
            t.Change(u,x,0);
        }else if(opt==1) 
            t.Change(u,0,1);
        else cout<<t.Query(u)<<'\n';
    }
}
void init() {
    cin>>n>>m;
    for(int i=1;i<=n;++i) 
        cin>>a[i];
    for(int i=1;i<=n;++i) 
        cin>>c[i];
    int u,v;
    for(int i=1;i<n;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    Dfs(1,0);
    t.Init();
}
int main() {
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
    // while(cin>>n) {
    while(T--) {
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}