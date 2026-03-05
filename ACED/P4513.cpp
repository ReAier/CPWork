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
int a[maxn];

struct SegTree{
    struct node{
        int pre,suf,sum,ma,mx;
        node operator+(const node &x)const{
            node ans=x;
            ans.pre=max(pre,sum+x.pre);
            ans.suf=max(x.suf,x.sum+suf);
            ans.sum=sum+x.sum;
            ans.ma=max(ma,x.ma);
            ans.mx=max(max(mx,x.mx),suf+x.pre);
            return ans;
        }
    }t[maxn];
#define ls(u) (u<<1)
#define rs(u) (u<<1|1)
#define pre(u) t[u].pre
#define suf(u) t[u].suf
#define sum(u) t[u].sum
#define ma(u) t[u].ma
#define mx(u) t[u].mx
    void PushUp(int p){
        t[p]=t[ls(p)]+t[rs(p)];
    }
    void Build(int p,int l,int r){
        if(l==r) return mx(p)=pre(p)=suf(p)=a[l]>0?a[l]:0,ma(p)=sum(p)=a[l],void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    node Query(int p,int l,int r,int L,int R){
        if(l>R||r<L) return (node){-INF,-INF,0,-INF,-INF};
        if(L<=l&&r<=R) return t[p];
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    int Query2(int p,int l,int r,int L,int R){
        if(l>R||r<L) return -INF;
        if(L<=l&&r<=R) return ma(p);
        int mid=l+r>>1;
        return max(Query2(ls(p),l,mid,L,R),Query2(rs(p),mid+1,r,L,R));
    }
    void Change(int p,int l,int r,int x,int k){
        if(l==r) return mx(p)=pre(p)=suf(p)=k>0?k:0,ma(p)=sum(p)=k,void(); 
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k); 
        PushUp(p);
    }
    int Query(int l,int r){
        int tmp=Query2(1,1,n,l,r);
        if(tmp<0) return tmp;
        return Query(1,1,n,l,r).mx;
    }
    void Change(int x,int k){
        Change(1,1,n,x,k);
    }
    void init(){
        Build(1,1,n);
    }
}t;

void solve(){
    int opt,x,k;
    while(m--){
        cin>>opt>>x>>k;
        if(opt==1){
            if(x>k) swap(x,k);
            cout<<t.Query(x,k)<<endl;
        }else{
            t.Change(x,k);
        }
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
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