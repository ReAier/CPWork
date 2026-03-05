#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=1e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m,L,R;
ll a[maxn],sum[maxn];
struct SegTree{
    struct Node{
        ll ls,rs,val,pri,siz;
    }t[maxn<<6];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define val(p) t[p].val
#define pri(p) t[p].pri
#define siz(p) t[p].siz
    mt19937 mt;
    ll rt,idx;
    ll NewNode(ll val){
        t[++idx]={0,0,val,int(mt()),1};
        return idx;
    }
    void PushUp(ll p){
        siz(p)=siz(ls(p))+siz(rs(p))+1;
    }
    void Split(ll p,ll val,ll &l,ll &r){
        if(!p) return l=r=0,void();
        if(val(p)<=val) {
            l=p;
            Split(rs(p),val,rs(p),r);
        }else{
            r=p;
            Split(ls(p),val,l,ls(p));
        }PushUp(p);
    }
    ll Merge(ll l,ll r){
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
    void Insert(ll val){
        ll l,r;
        Split(rt,val,l,r);
        rt=Merge(Merge(l,NewNode(val)),r);
    }
    ll Query(ll L,ll R){
        ll l,p,r,ans;
        Split(rt,L-1,l,p);
        Split(p,R,p,r);
        ans=siz(p);
        rt=Merge(Merge(l,p),r);
        return ans;
    }
}t;

void solve(){
    ll ans=0,tmp=0;
    t.Insert(0);
    for(int i=1;i<=n;++i){
        ans+=t.Query(sum[i]-R,sum[i]-L);
        t.Insert(sum[i]);
    }
    cout<<ans;
}
void init(){
    cin>>n>>L>>R;
    for(int i=1;i<=n;++i)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
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