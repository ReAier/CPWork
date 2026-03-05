#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;

struct Tr{
    mt19937 mt;
    struct node{
        ull ls,rs,val,pri,len,tag,siz,sum;
    }t[maxn];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define val(p) t[p].val
    #define pri(p) t[p].pri
    #define len(p) t[p].len
    #define tag(p) t[p].tag
    #define siz(p) t[p].siz
    #define sum(p) t[p].sum
    ull root,idx;
    ull NewNode(ll val,ll len){
        t[++idx]=(node){0,0,val,mt(),len,0,len,val*len};
        return idx;
    }
    void AddTag(ull p,ull k){
        if(!p) return;
        tag(p)+=k;
        val(p)+=k;
        sum(p)+=siz(p)*k;
    }
    void PushUp(ull p){
        siz(p)=siz(ls(p))+siz(rs(p))+len(p);
        sum(p)=sum(ls(p))+sum(rs(p))+val(p)*len(p);
    }
    void PushDown(ull p){
        if(!tag(p)) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)=0;
    }
    ull Merge(ull l,ull r){
        if(!l||!r) return l|r;
        if(pri(l)>pri(r)){
            PushDown(l);
            rs(l)=Merge(rs(l),r);
            PushUp(l);
            return l;
        }else{
            PushDown(r);
            ls(r)=Merge(l,ls(r));
            PushUp(r);
            return r;
        }
    }
    ull SplitNode(ull Lp,ull len){
        PushDown(Lp);
        int Rp=NewNode(val(Lp),len(Lp)-len);
        len(Lp)=len;
        rs(Rp)=rs(Lp);
        rs(Lp)=0;
        PushUp(Rp),PushUp(Lp);
        return Rp;
    }
    void Split(ull p,ull siz,ull &l,ull &r){
        if(!p) return l=r=0,void();
        PushDown(p);
        if(siz(ls(p))+len(p)<=siz){
            l=p;
            Split(rs(p),siz-siz(ls(p))-len(p),rs(p),r);
        }else if(siz(ls(p))>=siz){
            r=p;
            Split(ls(p),siz,l,ls(p));
        }else{
            int np=SplitNode(p,siz-siz(ls(p)));
            l=p,r=np;
        }
        PushUp(p);
    }
    void Add(ull l,ull r,ull k){
        ull L,R,p;
        Split(root,l-1,L,p);
        Split(p,r-l+1,p,R);
        AddTag(p,k);
        root=Merge(L,Merge(p,R));
    }
    ull Query(ull l,ull r){
        ull L,R,p,ans;
        Split(root,l-1,L,p);
        Split(p,r-l+1,p,R);
        ans=sum(p);
        root=Merge(L,Merge(p,R));
        return ans;
    }
    void Init(){
        root=NewNode(0,n);
    }
}t;


void solve(){
    ull opt,l,r,k;
    while(m--){
        scanf("%lld%lld%lld",&opt,&l,&r);
        if(opt==1){
            scanf("%lld",&k);
            t.Add(l,r,k);
        }else{
            cout<<t.Query(l,r)+(l+r)*(r-l+1ull)/2ull<<'\n';
        }
    }
}

void init(){
    cin>>n>>m;
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