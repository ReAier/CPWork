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
int n,m,V=1e9;
int a[maxn];
struct SegTree{
    struct Node{
        int ls,rs,sum;
    }t[maxn<<4];
    int idx=0,rt=0;
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define sum(p) t[p].sum
    void Add(int &p,int l,int r,int x,int k){
        if(!p) p=++idx;
        if(l==r) return sum(p)+=k,void();
        int mid=l+r>>1;
        if(x<=mid) Add(ls(p),l,mid,x,k);
        else Add(rs(p),mid+1,r,x,k);
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    int Query(int p,int l,int r,int L,int R){
        if(!p) return 0;
        if(L<=l&&R>=r) return sum(p);
        if(L>r||R<l) return 0;
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    void Add(int x,int k){
        Add(rt,1,V,x,k);
    }
    int Query(int l,int r){
        l=max(1,l),r=min(r,V);
        return Query(rt,1,V,l,r);
    }
}t;
void solve(){
    ll ans=0,l=1;
    for(int r=1;r<=n;++r){
        t.Add(a[r],1);
        while(t.Query(a[r]-m+1,a[r]+m-1)>1)
            t.Add(a[l++],-1);
        ans+=r-l+1;
    }
    cout<<ans;
}
void init(){
    cin>>n>>m;
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