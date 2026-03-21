#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m;
ll a[maxn];
ll ans[maxn];
struct FHQ{
    struct Node{
        ll ls,rs,val,id;
        ll tag,sum;
        unsigned int pri;
    }t[maxn];
    ll Brt,Srt,idx;
    mt19937 mt;
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define val(p) t[p].val
#define id(p) t[p].id
#define tag(p) t[p].tag 
#define sum(p) t[p].sum 
#define pri(p) t[p].pri 
    ll NewNode(ll val,ll id){
        t[++idx]={0,0,val,id,0,0,mt()};
        return idx;
    }
    void AddTag(ll p,ll k){
        if(!p) return;
        tag(p)+=k;
        sum(p)+=k;
    }
    void PushDown(ll p){
        if(!tag(p)) 
            return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)=0;
    }
    void Split(ll p,ll x,ll &l,ll &r){
        if(!p) return l=r=0,void();
        PushDown(p);
        if(val(p)<=x){
            l=p;
            Split(rs(p),x,rs(p),r);
        }else{
            r=p;
            Split(ls(p),x,l,ls(p));
        }
    }
    ll Merge(ll l,ll r){
        if(!l||!r) return l|r;
        if(pri(l)<pri(r)){
            PushDown(l);
            rs(l)=Merge(rs(l),r);
            return l;
        }else{
            PushDown(r);
            ls(r)=Merge(l,ls(r));
            return r;
        }
    }
    void Insert(ll val,ll id){
        ll Bp,Sp;
        Split(Brt,val-1,Bp,Brt);
        Split(Srt,val,Srt,Sp);
        AddTag(Bp,val);
        AddTag(Sp,val);
        Brt=Merge(NewNode(val,id),Merge(Sp,Brt));
        Srt=Merge(Srt,Bp);
    }
    void Dfs(ll p){
        if(!p) return;
        ans[id(p)]=sum(p);
        PushDown(p);
        Dfs(ls(p));
        Dfs(rs(p));
    }
    void Answer(){
        Dfs(Brt);
        Dfs(Srt);
    }
}t;

void solve(){
    for(int i=1;i<=n;++i) 
        t.Insert(a[i],i);
    t.Answer();
    for(int i=1;i<=n;++i) 
        cout<<ans[i]<<" ";
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
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