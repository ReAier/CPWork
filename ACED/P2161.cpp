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

struct FHQ{
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define siz(p) t[p].siz
#define pri(p) t[p].pri
#define val(p) t[p].val
    struct plan{
        int l,r;
        bool operator<(const plan &x)const{
            return r<x.l;
        }
    };
    struct node{
        int ls,rs,siz,pri;
        plan val;
        bool operator<(const node &x)const{
            return val<x.val;
        }
    }t[maxn];
    int idx,root;
    int NewNode(int l,int r){
        t[++idx]=(node){0,0,1,rand(),l,r};
        return idx;
    }
    void PushUp(int p){
        siz(p)=siz(ls(p))+siz(rs(p))+1;
    }
    void split(int p,plan val,int &l,int &r){
        if(!p) return l=r=0,void();
        if(val(p)<val){
            l=p,split(rs(p),val,rs(p),r);
        }else{
            r=p,split(ls(p),val,l,ls(p));
        }
        PushUp(p);
    }
    void split2(int p,plan val,int &l,int &r){
        if(!p) return l=r=0,void();
        if(val<val(p)){
            r=p,split2(ls(p),val,l,ls(p));
        }else{
            l=p,split2(rs(p),val,rs(p),r);
        }
        PushUp(p);
    }
    int merge(int l,int r){
        if(!l||!r) return l|r;
        if(pri(l)>pri(r)){
            rs(l)=merge(rs(l),r);
            PushUp(l);
            return l;
        }else{
            ls(r)=merge(l,ls(r));
            PushUp(r);
            return r;
        }
    }
    int insert(int l,int r){
        int lp,rp,p;
        plan x=(plan){l,r};
        split(root,x,lp,rp);
        split2(rp,x,p,rp);
        root=merge(lp,merge(NewNode(l,r),rp));
        return siz(p);
    }
    int query(){
        return siz(root);
    }
}t;



void solve(){
    char opt;
    int l,r;
    while(n--){
        cin>>opt;
        if(opt=='A'){
            cin>>l>>r;
            cout<<t.insert(l,r)<<endl;
        }else{
            cout<<t.query()<<endl;
        }
    }
}

void init(){
    cin>>n;
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