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
int a[maxn];
vector<pair<int,int>>Q[maxn];
struct SegTree{
    struct Node{
        int mi;
    }t[maxn];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mi(p) t[p].mi
    void PushUp(int p){
        mi(p)=min(mi(ls(p)),mi(rs(p)));
    }
    void Change(int p,int l,int r,int x,int k){
        if(l==r) return mi(p)=k,void();
        int mid=l+r>>1;
        if(x<=mid)
            Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    int Query(int p,int l,int r,int k){
        if(l==r) return l;
        int mid=l+r>>1;
        if(mi(ls(p))<k)
            return Query(ls(p),l,mid,k);
        else return Query(rs(p),mid+1,r,k);
    }
    void Change(int x,int k){
        Change(1,1,n+10,x+1,k);
    }
    int Query(int k){
        return Query(1,1,n+10,k)-1;
    }
}t;
int ans[maxn];
void solve(){
    for(int r=1;r<=n;++r){
        if(a[r]<=n) 
            t.Change(a[r],r);
        for(auto [l,id]:Q[r])
            ans[id]=t.Query(l);
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int l,r;
    for(int i=1;i<=m;++i){
        cin>>l>>r;
        Q[r].push_back({l,i});
    }
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