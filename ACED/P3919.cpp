#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
int a[maxn];

struct SegTree{
    struct node{
        int ls,rs,val;
    }t[maxn<<6];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define val(p) t[p].val
    int idx,root[maxn],rtidx;
    int CopyNode(int p){
        t[++idx]=t[p];
        return idx;
    }
    void Change(int &p,int l,int r,int x,int k){
        p=CopyNode(p);
        if(l==r) return val(p)=k,void();
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
    }
    int Query(int p,int l,int r,int x){
        if(l==r) return val(p);
        int mid=l+r>>1;
        if(x<=mid) return Query(ls(p),l,mid,x);
        else return Query(rs(p),mid+1,r,x);
    }
    void Change(int v,int x,int k){
        root[++rtidx]=root[v];
        Change(root[rtidx],1,n,x,k);
    }
    int Query(int v,int x){
        root[++rtidx]=root[v];
        return Query(root[rtidx],1,n,x);
    }
    void Build(int &p,int l,int r){
        p=++idx;
        if(l==r) return val(p)=a[l],void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
    }
    void Init(){
        Build(root[0],1,n);
    }
}t;


void solve(){
    int v,opt,p,k;
    while(m--){
        cin>>v>>opt>>p;
        if(opt==1){
            cin>>k;
            t.Change(v,p,k);
        }else{
            cout<<t.Query(v,p)<<endl;
        }
    }
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    t.Init();
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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