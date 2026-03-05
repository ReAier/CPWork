#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Mat{
    ll x1,x2,y,w;
    bool operator<(Mat x){
        return y<x.y;
    }
}a[maxn];
ll x[maxn],nx,y[maxn],ny;
map<ll,ll>mp;
struct SegTree{
    struct Node{
        ll len,val,sum;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define len(p) t[p].len
#define val(p) t[p].val
#define sum(p) t[p].sum
    void PushUp(int p){
        if(val(p)) sum(p)=len(p); 
        else sum(p)=sum(ls(p))+sum(rs(p));
    }
    void AddTag(int p,int k){
        val(p)+=k;
        PushUp(p);
    }
    void Change(int p,int l,int r,int L,int R,int k){
        if(L<=l&&R>=r) 
            return AddTag(p,k);
        if(L>r||R<l) return;
        int mid=l+r>>1;
        Change(ls(p),l,mid,L,R,k);
        Change(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    void Build(int p,int l,int r){
        if(l==r) return len(p)=x[l+1]-x[l],void();   
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        len(p)=len(ls(p))+len(rs(p));
    }
    void Init(){Build(1,1,nx-1);}
    void Change(int l,int r,int k){
        Change(1,1,nx-1,l,r,k);
    }
    ll Query(){
        return sum(1);
    }
}t;

void solve(){
    ll ans=0,now=0;
    for(int i=1;i<=m;++i){
        if(y[now]<a[i].y){
            ans+=(a[i].y-y[now])*t.Query();
            ++now;
        }
        t.Change(a[i].x1,a[i].x2,a[i].w);
    }
    cout<<ans;
}
void init(){
    cin>>n;
    int x1,x2,y1,y2;
    for(int i=1;i<=n;++i){
        cin>>x1>>y1>>x2>>y2;
        if(y1>y2) swap(y1,y2);
        if(x1>x2) swap(x1,x2);
        a[++m]={x1,x2,y1,1};
        a[++m]={x1,x2,y2,-1};
        x[++nx]=x1,x[++nx]=x2;
        y[++ny]=y1,y[++ny]=y2;
    }
    sort(a+1,a+1+m);
    sort(x+1,x+1+nx),sort(y+1,y+1+ny);
    nx=unique(x+1,x+1+nx)-x-1;
    ny=unique(y+1,y+1+ny)-y-1;
    for(int i=1;i<=nx;++i) mp[x[i]]=i;
    for(int i=1;i<=m;++i) 
        a[i].x1=mp[a[i].x1],a[i].x2=mp[a[i].x2]-1;
    t.Build(1,1,nx-1);
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