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
int n,m;
struct FHQ{
    struct Node{
        //le 未匹配左 ri 右
        int ls,rs,le,ri,siz,pri;
        bool val;//0 ( 1 )
    }t[maxn];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define le(p) t[p].le
#define ri(p) t[p].ri
#define siz(p) t[p].siz
#define pri(p) t[p].pri
#define val(p) t[p].val
    int rt,idx;
    mt19937 mt;
    int NewNode(bool val){
        t[++idx]={0,0,!val,val,1,int(mt()),val};
        return idx;
    }
    void PushUp(int p){
        siz(p)=siz(ls(p))+siz(rs(p))+1;
        int Pi=min(le(ls(p))+!val(p),ri(rs(p))+val(p));
        le(p)=le(ls(p))+le(rs(p))-Pi+!val(p);
        ri(p)=ri(ls(p))+ri(rs(p))-Pi+val(p);
    }
    int Merge(int l,int r){
        if(!l||!r) return l|r;
        if(pri(l)>pri(r)){
            rs(l)=Merge(rs(l),r);
            PushUp(l);
            return l;
        }else{
            ls(r)=Merge(l,ls(r));
            PushUp(r);
            return r;
        }
    }
    void Split(int p,int siz,int &L,int &R){
        if(!p) return L=R=0,void();
        if(siz(ls(p))+1<=siz){
            L=p;
            Split(rs(p),siz-siz(ls(p))-1,rs(p),R);
        }
        else{
            R=p;
            Split(ls(p),siz,L,ls(p));
        }
        PushUp(p);
    }
    void Pr(int p){
        if(!p) return;
        Pr(ls(p));
        cout<<val(p);
        Pr(rs(p));
    }
    int Insert(int L,int R){
        int l,p,r,ans;
        Split(rt,L,l,p);
        Split(p,R-L,p,r);
        ans=le(p)+ri(p);
        rt=Merge(Merge(l,NewNode(0)),Merge(p,Merge(NewNode(1),r)));
        return ans;
    }
}t;


void solve(){
    int l,r;
    while(n--){
        cin>>l>>r;
        cout<<t.Insert(l,r)*2<<'\n';
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