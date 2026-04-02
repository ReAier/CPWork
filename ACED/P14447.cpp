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
const int maxn=3e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int a[maxn],b[maxn];
int nab[maxn],idx,idx2;
map<int,int>mp;

struct Query{
    int u,na,nb;
}q[maxn];

multiset<int>B[maxn];
struct SegTree{
    struct Info{
        int mxa,mxab;
        int lb,ra;
        int cnt;
        Info operator+(const Info &x)const{
            Info res;
            res.cnt=cnt+x.cnt;
            if(mxa>=x.mxa)
                res.mxa=mxa,res.mxab=mxab;
            else res.mxa=x.mxa,res.mxab=x.mxab;
            if(ra>=x.lb)
                res.ra=max(ra,x.ra),res.lb=lb;
            else res.ra=x.ra,res.lb=x.lb;
            return res;
        }
    };
    struct Node{
        Info sum;
    }t[maxn<<1];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define sum(p) t[p].sum
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Change(int p,int l,int r,int x,int na,int k){
        if(l==r){
            if(~k) B[x].insert(na);
            else B[x].erase(B[x].find(na));
            sum(p).cnt+=k;
            if(B[x].size()) 
                sum(p).mxa=sum(p).ra=*B[x].rbegin(),sum(p).lb=sum(p).mxab=x;
            else sum(p)={};
            return;
        }
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,na,k);
        else Change(rs(p),mid+1,r,x,na,k);
        PushUp(p);
    }
    void Change(int u,int na,int nb){
        Change(1,1,n,b[u],a[u],-1);
        b[u]=nb,a[u]=na;
        Change(1,1,n,b[u],a[u],1);
    }
    Info Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return sum(p);
        if(L>r||R<l) return {};
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    int Query(){
        int mxa=sum(1).mxa,mxab=sum(1).mxab;
        Info R=Query(1,1,n,mxa+1,n),L=Query(1,1,n,1,mxab-1);
        if(L.ra>=mxab) mxab=min(mxab,L.lb);
        if(R.mxa>=mxab) return R.cnt;
        return R.cnt+(mxab<=mxa);
    }
    void Build(int p,int l,int r){
        if(l==r){
            if(B[l].size()){
                sum(p).cnt=B[l].size();
                sum(p).mxa=sum(p).ra=*B[l].rbegin();
                sum(p).mxab=sum(p).lb=l;
            }
            return;
        }int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
}t;

void solve(){
    cout<<t.Query()<<"\n";
    for(int i=1;i<=m;++i){
        auto[u,na,nb]=q[i];
        t.Change(u,na,nb);
        cout<<t.Query()<<'\n';
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)   
        cin>>a[i]>>b[i],nab[++idx2]=a[i],nab[++idx2]=b[i];
    for(int i=1;i<=m;++i)
        cin>>q[i].u>>q[i].na>>q[i].nb,nab[++idx2]=q[i].na,nab[++idx2]=q[i].nb;
    sort(nab+1,nab+1+idx2);
    for(int i=1;i<=idx2;++i){
        if(!mp[nab[i]])
            mp[nab[i]]=++idx;
    }
    for(int i=1;i<=n;++i)
        B[b[i]=mp[b[i]]].insert(a[i]=mp[a[i]]);
    for(int i=1;i<=m;++i)
        q[i].nb=mp[q[i].nb],q[i].na=mp[q[i].na];
    n=idx;
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