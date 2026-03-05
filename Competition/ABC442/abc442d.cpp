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
int n,m;
int a[maxn];
struct SegTree{
    struct Node{
        int sum;
    }t[maxn];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define sum(p) t[p].sum
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Build(int p,int l,int r){
        if(l==r) return sum(p)=a[l],void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Change(int p,int l,int r,int x,int k){
        if(l==r) 
            return sum(p)=k,void();
        int mid=l+r>>1;
        if(x<=mid) 
            Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    ll Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r)
            return sum(p);
        if(L>r||R<l)     
            return 0;
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    ll Query(int l,int r){
        return Query(1,1,n,l,r);
    }
    void Change(int x){
        int Qx1=Query(x,x),Qx2=Query(x+1,x+1);
        Change(1,1,n,x,Qx2),Change(1,1,n,x+1,Qx1);
    }
}t;

void solve(){
    int op,l,r;
    while(m--){
        cin>>op>>l;
        if(op==1)
            t.Change(l);
        else cin>>r,cout<<t.Query(l,r)<<'\n';
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