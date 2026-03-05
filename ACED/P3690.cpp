#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct LCT{
    struct Node{
        int ch[2],fa,val,sum,tag;
    }t[maxn];
#define ls(p) t[p].ch[0]
#define rs(p) t[p].ch[1]
#define ch(p) t[p].ch
#define fa(p) t[p].fa
#define val(p) t[p].val
#define sum(p) t[p].sum
#define tag(p) t[p].tag
    int NewNode(int val){
        static int idx=0;
        t[++idx]={0,0,0,val,val,0};
        return idx;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))^sum(rs(p))^val(p);
    }
    void AddTag(int p){
        swap(ls(p),rs(p));
        tag(p)^=1;
    }
    void PushDown(int p){
        if(!tag(p)) return;
        AddTag(ls(p)),AddTag(rs(p));
        tag(p)=0;
    }
    bool IsRoot(int p){
        return ls(fa(p))!=p&&rs(fa(p))!=p;
    }
    void PushAll(int p){
        if(!IsRoot(p)) PushAll(fa(p));
        PushDown(p);
    }
    void Rotate(int p){
        int fp=fa(p),ffp=fa(fp),k=p==rs(fp);
        if(!IsRoot(fp)){
            ch(ffp)[fp==rs(ffp)]=p;
        }fa(p)=ffp;
        ch(fp)[k]=ch(p)[k^1],fa(ch(p)[k^1])=fp;
        ch(p)[k^1]=fp,fa(fp)=p;
        PushUp(fp),PushUp(p);
    }
    void Splay(int p){
        PushAll(p);
        while(!IsRoot(p)){
            int fp=fa(p),ffp=fa(fp);
            if(!IsRoot(fp))
                Rotate((ls(ffp)==fp)^(ls(fp)==p)?p:fp);
            Rotate(p);
        }
    }
    void Access(int p){
        for(int sp=0;p;sp=p,p=fa(p)){
            Splay(p);
            rs(p)=sp;
            PushUp(p);
        }
    }
    void MakeRoot(int p){
        Access(p);
        Splay(p);
        AddTag(p);
    }
    int FindRoot(int p){
        Access(p);
        Splay(p);
        while(ls(p)) p=ls(p);
        return p;
    }
    void Link(int u,int v){
        MakeRoot(u);
        if(FindRoot(v)!=u)
            fa(u)=v;
    }
    void Cut(int u,int v){
        MakeRoot(u);
        Access(v);
        Splay(v);
        if(ls(v)==u&&!rs(u))
            ls(v)=fa(u)=0;
        PushUp(v);
    }
    int Query(int u,int v){
        MakeRoot(u);
        Access(v);
        Splay(v);
        return sum(v);
    }
    void Change(int u,int k){
        Splay(u);
        val(u)=k;
        PushUp(u);
    }
    void Init(){
        for(int i=1;i<=n;++i)
            NewNode(a[i]);
    }
}t;

void solve(){
    int op,u,v;
    while(m--){
        cin>>op>>u>>v;
        switch (op)
        {
        case 0:
            cout<<t.Query(u,v)<<'\n';
            break;
        case 1:
            t.Link(u,v);
            break;
        case 2:
            t.Cut(u,v);
            break;
        case 3:
            t.Change(u,v);
            break;
        }
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
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