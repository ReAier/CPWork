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

struct SegTree{
    struct node{
        int sum,len;
        bool tag;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define sum(p) t[p].sum
#define len(p) t[p].len
#define tag(p) t[p].tag
    void Build(int p,int l,int r){
        len(p)=r-l+1;
        if(l==r) return;
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void AddTag(int p){
        tag(p)^=1;
        sum(p)=len(p)-sum(p);
    }
    void PushDown(int p){
        if(!tag(p)) return;
        tag(p)=0;
        AddTag(ls(p));
        AddTag(rs(p));
        PushUp(p);
    }
    void Change(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return AddTag(p);
        if(R<l||L>r) return;
        PushDown(p);
        int mid=l+r>>1;
        Change(ls(p),l,mid,L,R);
        Change(rs(p),mid+1,r,L,R);
        PushUp(p);
    }
    int Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return sum(p);
        if(R<l||L>r) return 0;
        PushDown(p);
        int mid=l+r>>1,ans;
        ans=Query(ls(p),l,mid,L,R);
        ans+=Query(rs(p),mid+1,r,L,R);
        PushUp(p);
        return ans;
    }
    void Change(int l,int r){
        Change(1,1,n,l,r);
    }
    int Query(int l,int r){
        return Query(1,1,n,l,r);
    }
    void init(){
        Build(1,1,n);
    }
}t;


void solve(){
    int opt,l,r;
    while(m--){
        cin>>opt>>l>>r;
        if(opt) cout<<t.Query(l,r)<<endl;
        else t.Change(l,r);
    }
}

void init(){
    cin>>n>>m;
    t.init();
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