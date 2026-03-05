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
const double eps=1e-8;
ll n,m;
ll a[maxn];

struct SegTrees{
    struct Node{
        ll ls,rs;
        ll sum;
    }t[maxn<<2];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define sum(p) t[p].sum
    ll root[maxn],idx,rtidx;
    void PushUp(ll p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Split(ll l,ll &r,ll k){
        if(!l) return;
        r=++idx;
        if(sum(ls(l))<k) Split(rs(l),rs(r),k-sum(ls(l)));
        else swap(rs(l),rs(r));
        if(sum(ls(l))>k) Split(ls(l),ls(r),k);
        sum(r)=sum(l)-k;
        sum(l)=k;
    }
    ll Merge(ll l,ll r){
        if(!l||!r) return l|r;
        sum(l)+=sum(r);
        ls(l)=Merge(ls(l),ls(r));
        rs(l)=Merge(rs(l),rs(r));
        return l;
    }
    void Modify(ll &p,ll l,ll r,ll x,ll k){
        if(!p) p=++idx;
        if(l==r) return sum(p)+=k,void();
        sum(p)+=k;
        ll mid=l+r>>1;
        if(x<=mid) Modify(ls(p),l,mid,x,k);
        else Modify(rs(p),mid+1,r,x,k);
    }
    ll Query(ll p,ll l,ll r,ll L,ll R){
        if(!p||l>R||r<L) return 0;
        if(L<=l&&R>=r) return sum(p);
        ll mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    ll FindKth(ll p,ll l,ll r,ll k){
        if(l==r) return l;
        ll mid=l+r>>1;
        if(sum(ls(p))>=k) return FindKth(ls(p),l,mid,k);
        else return FindKth(rs(p),mid+1,r,k-sum(ls(p)));
    }
    void Build(ll &p,ll l,ll r){
        p=++idx;
        if(l==r) return sum(p)=a[l],void();
        ll mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Init(){
        Build(root[++rtidx],1,n);
    }
    void Move1(ll p,ll l,ll r){
        ll LNum=Query(root[p],1,n,1,l-1),PNum=Query(root[p],1,n,l,r);
        ll Rrt;
        Split(root[p],root[++rtidx],LNum);
        Split(root[rtidx],Rrt,PNum);
        root[p]=Merge(root[p],Rrt);
    }
    void Move2(ll p,ll t){
        root[p]=Merge(root[p],root[t]);
    }
    void Modify(ll p,ll x,ll k){
        Modify(root[p],1,n,x,k);
    }
    ll Query(ll p,ll l,ll r){
        return Query(root[p],1,n,l,r);
    }
    ll FindKth(ll p,ll k){
        if(sum(root[p])<k) return -1;
        return FindKth(root[p],1,n,k);
    }
}t;

void solve(){
    ll opt,p,l,r;
    while(m--){
        cin>>opt>>p>>l;
        switch(opt){
            case 0:
            cin>>r;
            t.Move1(p,l,r);
            break;
            case 1:
            t.Move2(p,l);
            break;
            case 2:
            cin>>r;
            t.Modify(p,r,l);
            break;
            case 3:
            cin>>r;
            cout<<t.Query(p,l,r)<<endl;
            break;
            case 4:
            cout<<t.FindKth(p,l)<<endl;
            break;
        }
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
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