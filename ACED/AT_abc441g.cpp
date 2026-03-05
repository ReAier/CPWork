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
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
struct Tag{
    ll add,zero;
    bool operator==(Tag x){
        return add==x.add&&zero==x.zero;
    }
    Tag operator+(Tag x){
        Tag res=*this;
        if(x.zero)
            res={0,1+((zero+x.zero-1)%2)};
        res.add+=x.add;
        return res;
    }
};
struct Info{
    ll mx,cnt,len;
    Info operator+(Info x){
        return {max(mx,x.mx),cnt+x.cnt,len+x.len};
    }
    Info operator+(Tag x){
        Info res=*this;
        if(x.zero==1)
            res.mx=0,res.cnt=len-cnt;
        else if(x.zero==2)
            res.mx=0;
        if(res.cnt)
            res.mx+=x.add;
        return res;
    }
};
const Tag Itag={0,0};
const Info Iinfo={0,0,0};


struct SegTree{
    struct Node{
        Info info;
        Tag tag;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define info(p) t[p].info
#define tag(p) t[p].tag
    void AddTag(int p,Tag k){
        tag(p)=tag(p)+k;
        info(p)=info(p)+k;
    }
    void PushDown(int p){
        if(tag(p)==Itag) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)=Itag;
    }
    void PushUp(int p){
        info(p)=info(ls(p))+info(rs(p));
    }
    void Add(int p,int l,int r,int L,int R,Tag k){
        if(L<=l&&R>=r) return AddTag(p,k);
        if(l>R||r<L) return;
        PushDown(p);
        ll mid=(l+r)>>1;
        Add(ls(p),l,mid,L,R,k);
        Add(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    Info Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return info(p);
        if(l>R||r<L) return Iinfo;
        PushDown(p);
        ll mid=(l+r)>>1;
        Info ans=Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
        PushUp(p);
        return ans;
    }
    void Add(int l,int r,Tag k){
        Add(1,1,n,l,r,k);
    }
    Info Query(ll l,ll r){
        return Query(1,1,n,l,r);
    }
    void Build(int p,int l,int r){
        if(l==r) {
            info(p)={0,1,1};
            return;
        }
        ll mid=(l+r)>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
}t;


void solve(){
    ll op,l,r,k;
    while(m--){
        cin>>op>>l>>r;
        if(op==1){
            cin>>k;
            t.Add(l,r,{k,0});
        }else if(op==2)
            t.Add(l,r,{0,1});
        else cout<<t.Query(l,r).mx<<'\n';
    }
}
void init(){
    cin>>n>>m;
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