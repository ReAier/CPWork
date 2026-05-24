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

struct Info{
    int siz;
    Info(int sz=0){siz=sz;}
    Info operator+(const Info &x)const{return {siz+x.siz};}
    Info operator-(const Info &x)const{return {siz-x.siz};}
};

struct LCT{
    struct Node{
        int ch[2],rev,fa;
        Info val,sum;
        Info vsum,tsum;
    }t[maxn];
#define ls(p) t[p].ch[0]
#define rs(p) t[p].ch[1]
#define ch(p) t[p].ch
#define val(p) t[p].val
#define sum(p) t[p].sum
#define vsum(p) t[p].vsum
#define tsum(p) t[p].tsum
#define rev(p) t[p].rev
#define fa(p) t[p].fa
    int idx;
    void Rev(int p){
        swap(rs(p),ls(p));
        rev(p)^=1;
    }
    void PushDown(int p){
        if(rev(p)) Rev(ls(p)),Rev(rs(p)),rev(p)=0;
    }
    int NewNode(Info val){
        t[++idx]={0,0,0,0,val,val,{},{}};
        return idx;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+val(p)+sum(rs(p));
        tsum(p)=tsum(ls(p))+val(p)+tsum(rs(p))+vsum(p);
    }
    void PushAll(int p){
        if(!IsRoot(p)) PushAll(fa(p));
        PushDown(p);
    }
    bool IsRoot(int p){
        return ls(fa(p))!=p&&rs(fa(p))!=p;
    }
    void Rotate(int p){
        int fp=fa(p),ffp=fa(fp),k=rs(fp)==p;
        if(!IsRoot(fp))
            ch(ffp)[rs(ffp)==fp]=p;
        fa(p)=ffp;
        ch(fp)[k]=ch(p)[k^1],fa(ch(p)[k^1])=fp;
        ch(p)[k^1]=fp,fa(fp)=p;
        PushUp(fp),PushUp(p);
    }
    void Splay(int p){
        PushAll(p);
        while(!IsRoot(p)){
            int fp=fa(p),ffp=fa(fp);
            if(!IsRoot(fp)) 
                Rotate((ls(fp)==p)^(ls(ffp)==fp)?p:fp);
            Rotate(p);
        }
    }
    void Access(int p){
        for(int sp=0;p;sp=p,p=fa(p)){
            Splay(p);
            vsum(p)=vsum(p)+tsum(rs(p));
            vsum(p)=vsum(p)-tsum(sp);
            rs(p)=sp;
            PushUp(p);
        }
    }
    void MakeRoot(int p){
        Access(p);
        Splay(p);
        Rev(p);
    }
    int FindRoot(int p){
        Access(p);
        Splay(p);
        while(ls(p)) 
            p=ls(p);
        Splay(p);
        return p;
    }
    void Link(int u,int v){
        MakeRoot(u);
        if(FindRoot(v)!=u) {
            Access(v),Splay(v),fa(u)=v;
            vsum(v)=vsum(v)+tsum(u);
        }
        PushUp(v);
    }
    void Cut(int u,int v){
        MakeRoot(u);
        Access(v);
        Splay(v);
        if(ls(v)==u&&!rs(u)&&fa(u)==v)
            ls(v)=fa(u)=0;
        PushUp(v);
    }
    Info Query(int u,int rt){
        MakeRoot(rt);
        Access(u);
        Splay(u);
        return val(u)+vsum(u);
    }
    void Init(){
        val(0)=sum(0)=vsum(0)=tsum(0)={};
        for(int i=1;i<=n;++i)
            NewNode({1});
    }
}t;


void solve() {
    char opt;
    int u,v;
    while(m--){
        cin>>opt>>u>>v;
        if(opt=='Q'){
            ll ans=t.Query(v,u).siz;
            ans*=t.Query(u,v).siz;
            cout<<ans<<'\n';
        }else t.Link(u,v);
    }
}
void init() {
    cin>>n>>m;
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