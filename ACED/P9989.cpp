#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ull long long
#define ll unsigned long long
#define pii pair<int,int>
using namespace std;
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1ll<<32;
const double eps=1e-8;
int n,m;
ll a[maxn];
ll Lcm(ll u,ll v){
    ll d=gcd(u,v);
    __int128_t l=u/d*v;
    if(l>INF) return INF;
    return l;
}
struct SegTree{
    struct Node{
        ll lm,sum;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lm(p) t[p].lm
#define sum(p) t[p].sum
    void PushUp(int p){
        lm(p)=Lcm(lm(ls(p)),lm(rs(p)));
        sum(p)=(sum(ls(p))+sum(rs(p)))%mod;
    }
    void Build(int p,int l,int r){
        if(l==r) {
            return sum(p)=(lm(p)=a[l])%mod,void();
        }int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Change(int p,int l,int r,int L,int R,ll k){
        if(k%lm(p)==0||l>R||r<L) return;
        if(l==r) return sum(p)=(lm(p)=gcd(lm(p),k))%mod,void();
        int mid=l+r>>1;
        Change(ls(p),l,mid,L,R,k);
        Change(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    ll Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return sum(p);
        if(L>r||R<l) return 0;
        int mid=l+r>>1;
        return (Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R))%mod;
    }
    void Change(int l,int r,ll k){
        Change(1,1,n,l,r,k);
    }
    ll Query(int l,int r){
        return Query(1,1,n,l,r);
    }
}t; 
void solve(){
    ll op,l,r,x;
    while(m--){
        cin>>op>>l>>r;
        if(op==1){
            cin>>x;
            t.Change(l,r,x);
        }else cout<<t.Query(l,r)%mod<<'\n';
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    t.Build(1,1,n);
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