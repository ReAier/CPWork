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
const double eps=1e-8;
int n,m;
pair<int,int> a[maxn];
int b[maxn],c[maxn];

struct SegTree{
    struct node{
        int ls,rs,sum;
    }t[maxn<<4];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define sum(p) t[p].sum
    int root[maxn],idx;
    int CopyNode(int p){
        t[++idx]=t[p];
        return idx;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Change(int &p,int l,int r,int k){
        p=CopyNode(p);
        if(l==r) return sum(p)+=1,void();
        int mid=l+r>>1;
        if(k<=mid) Change(ls(p),l,mid,k);
        else Change(rs(p),mid+1,r,k);
        PushUp(p);
    }
    int Query(int u,int v,int l,int r,int k){
        if(l==r) return l;
        int s=sum(ls(v))-sum(ls(u)),mid=l+r>>1;
        if(s>=k) return Query(ls(u),ls(v),l,mid,k);
        else return Query(rs(u),rs(v),mid+1,r,k-s);
    }
    int Query(int l,int r,int k){
        return Query(root[l-1],root[r],1,n,k);
    }
    void Init(){
        for(int i=1;i<=n;++i){
            root[i]=root[i-1];
            Change(root[i],1,n,c[i]);
        }
    }
}t;


void solve(){
    int l,r,k;
    while(m--){
        cin>>l>>r>>k;
        cout<<b[t.Query(l,r,k)]<<endl;
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) b[i]=a[i].first,c[a[i].second]=i;
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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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