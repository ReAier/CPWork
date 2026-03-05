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
int a[maxn];
struct Info{
    ll A[2][2];
    Info(ll x=-1){
        if(~x){
            A[0][0]=INF,A[0][1]=x;
            A[1][0]=0,A[1][1]=x;
        }else A[0][0]=A[1][1]=0,A[0][1]=A[1][0]=INF;
    }
    Info operator+(const Info &x)const{
        Info ans;
        memset(ans.A,0x3f,sizeof(ans.A));
        for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k) 
            ans.A[i][j]=min(ans.A[i][j],A[i][k]+x.A[k][j]);
        return ans;
    }
};

struct SegTree{
    struct Node{
        Info val;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define val(p) t[p].val
    void PushUp(int p){
        val(p)=val(ls(p))+val(rs(p));
    }
    void Change(int p,int l,int r,int x,Info k){
        if(l==r) return val(p)=k,void();
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    void Change(int x,Info k){
        Change(1,1,n,x,k); 
    }
    void Build(int p,int l,int r){
        val(p)={};
        if(l==r) return val(p)={a[l]},void();
        ll mid=(l+r)>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Init(){
        Build(1,1,n);
    }
}t;

void solve(){
    int x,k;
    while(m--){
        cin>>x>>k;
        t.Change(x,{k});
        cout<<t.t[1].val.A[0][1]*2<<'\n';
    }
}
void init(){
    cin>>n;
    n--;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    t.Init();
    cin>>m;
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
