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
        int val;
    }t[maxn];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define val(p) t[p].val
    void Build(int p,int l,int r){
        if(l==r) return val(p)=a[l],void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        val(p)=val(ls(p))^val(rs(p));
    }
    pii Query(int p,int l,int r,int x,int k){
        if(l==r) return {0,k};
        int mid=l+r>>1;
        if(x<=mid){
            auto [cnt,v]=Query(ls(p),l,mid,x,k);
            if(v<val(rs(p))) 
                cnt+=(r-l+1)>>1;
            return {cnt,v^val(rs(p))};
        }else{
            auto [cnt,v]=Query(rs(p),mid+1,r,x,k);
            if(v<=val(ls(p)))
                cnt+=(r-l+1)>>1;
            return {cnt,v^val(ls(p))};
        }
    }
    int Query(int x,int k){
        return Query(1,1,n,x,k).first;
    }
}t;

void solve(){
    int x,k;
    while(m--){
        cin>>x>>k;
        cout<<t.Query(x,k)<<'\n';
    }
}
void init(){
    cin>>n>>m;
    n=(1<<n);
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
    cin>>T;
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