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

char buf[maxn<<4],*_s,*_t;
#define gc() (_s==_t && (_t=(_s=buf)+fread(buf,1,maxn<<4,stdin),_s==_t)?EOF:*_s++)
void read(int &x){
    int f=1;x=0;
    char ch=gc();
    for(;!isdigit(ch);ch=gc())
        if(ch=='-') f=-1;
    for(;isdigit(ch);ch=gc())
        x=x*10+ch-'0';
    x*=f;
}

int n,m;
int a[maxn];
vector<int>e[maxn];
int siz[maxn],son[maxn],fa[maxn];
struct Info{
    int M[2][2];
    Info(int val=-INF){
        M[0][0]=M[0][1]=0;
        M[1][0]=val,M[1][1]=-INF;
    }
    int *operator[](const int x){
        return M[x];
    }
};
Info Compress(Info &u,Info &v){
    Info res;
    res[0][0]=max(v[0][0]+u[0][0],v[0][1]+u[1][0]);
    res[0][1]=max(v[0][0]+u[0][1],v[0][1]+u[1][1]);
    res[1][0]=max(v[1][0]+u[0][0],v[1][1]+u[1][0]);
    res[1][1]=max(v[1][0]+u[0][1],v[1][1]+u[1][1]);
    return res;
}
Info Rake(Info &u,Info &v){
    Info res;
    res[0][0]=u[0][0]+max(v[0][0],v[1][0]);
    res[0][1]=u[0][1]+max(v[0][1],v[1][1]);
    res[1][0]=u[1][0]+max(v[0][0],v[1][0]);
    res[1][1]=u[1][1]+max(v[0][1],v[1][1]);
    return res;
}
struct TopTree{
    struct Node{
        int ls,rs,fa;
        Info val;
        bool ty;
        int siz;
    }t[maxn<<1];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define fa(p) t[p].fa
#define val(p) t[p].val
#define siz(p) t[p].siz
#define ty(p) t[p].ty
    int idx,rt;
    int NewNode(bool ty,int val=-INF){
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
            for(int v:e[u]) if(v^fa[u]&&v^son[u]) 
                L.push_back(Build(v));
            if(!L.size()) H.push_back(son[u]);
            else H.push_back(Merge(son[u],SubBuild(L,0,L.size()-1,1),1));
        }
        return SubBuild(H,0,H.size()-1,0);
    }
    void Change(int u,int k){
        val(u)={k};
        while(u=fa(u)) PushUp(u); 
    }
    int Query(){
        return max(val(rt)[0][0],val(rt)[1][0]);
    }
    void Init(){
        for(int i=1;i<=n+1;++i)
            NewNode(0,a[i]);
        rt=Build(n+1);
    }
}t;
void Dfs(int u,int p){
    siz[u]=1,fa[u]=p;
    for(int v:e[u]) if(v^p)
        Dfs(v,u),siz[u]+=siz[v],siz[v]>siz[son[u]]?son[u]=v:0;
}

void solve(){
    int u,w,lasans=0;
    while(m--){
        read(u),read(w);
        t.Change(u^lasans,w);
        cout<<(lasans=t.Query())<<'\n';
    }
}
void init(){
    read(n),read(m);
    for(int i=1;i<=n;++i)
        read(a[i]);
    int u,v;
    for(int i=1;i<n;++i)
        read(u),read(v),e[u].push_back(v),e[v].push_back(u);
    e[n+1].push_back(1),e[1].push_back(n+1);
    Dfs(n+1,0);
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