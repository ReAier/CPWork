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
        ull ls,rs;
        ull sum,tag;
    }t[maxn<<3];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define sum(p) t[p].sum
    #define tag(p) t[p].tag
    ull root,idx;
    void AddTag(ull &p,ull l,ull r,ull k){
        if(!p) p=++idx;
        tag(p)+=k;
        sum(p)+=k*(r-l+1ull);
    }
    void PushUp(ull p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void PushDown(ull p,ull l,ull r){
        if(!tag(p)) return;
        ull mid=l+r>>1;
        AddTag(ls(p),l,mid,tag(p));
        AddTag(rs(p),mid+1,r,tag(p));
        tag(p)=0;
    }
    void Change(ull &p,ull l,ull r,ull L,ull R,ull k){
        if(!p) p=++idx;
        if(L<=l&&R>=r) return AddTag(p,l,r,k);
        if(L>r||R<l) return;
        PushDown(p,l,r);
        ull mid=l+r>>1;
        Change(ls(p),l,mid,L,R,k);
        Change(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    ull Query(ull &p,ull l,ull r,ull L,ull R){
        if(!p) return 0;
        if(L<=l&&R>=r) return sum(p);
        if(L>r||R<l) return 0;
        PushDown(p,l,r);
        ull mid=l+r>>1;
        ull ans=Query(ls(p),l,mid,L,R);
        ans+=Query(rs(p),mid+1,r,L,R);
        PushUp(p);
        return ans;
    }
    void Change(ull l,ull r,ull k){
        Change(root,1,n,l,r,k);
    }
    ull Query(ull l,ull r){
        return Query(root,1,n,l,r);
    }
}t;


void solve(){
    int opt,l,r,k;
    while(m--){
        cin>>opt>>l>>r;
        if(opt==1){
            cin>>k;
            t.Change(l,r,k);
        }else{
            cout<<t.Query(l,r)+(l+r)*(r-l+1ull)/2ull<<"\n";
        }
    }
}

void init(){
    cin>>n>>m;
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