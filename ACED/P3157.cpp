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
const int maxn=1e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Node{
    ll pos,val,tim,ans;
    bool operator<(Node x){
        return tim>x.tim;
    }
}a[maxn];
ll pos[maxn];
struct BitTree{
    ll t[maxn];
    void Add(int x,int k){
        while(x<=n) 
            t[x]+=k,x+=lowbit(x);
    }
    ll Sum(int x){
        ll ans=0;
        while(x) 
            ans+=t[x],x-=lowbit(x);
        return ans;
    }
}t;
void CDQ(int l,int r){
    if(l==r) return;
    int mid=l+r>>1,i=l,j=mid+1;
    CDQ(l,mid),CDQ(mid+1,r);
    sort(a+l,a+mid+1),sort(a+mid+1,a+r+1);
    while(j<=r){
        while(a[i].tim>=a[j].tim&&i<=mid) 
            t.Add(a[i].val,1),++i;
        a[j].ans+=t.Sum(n)-t.Sum(a[j].val);
        ++j;
    }
    for(int k=l;k<i;++k)
        t.Add(a[k].val,-1);
    i=l,j=mid+1;
    while(i<=mid){
        while(a[j].tim>=a[i].tim&&j<=r)
            t.Add(a[j].val,1),++j;
        a[i].ans+=t.Sum(a[i].val-1);
        ++i;
    }
    for(int k=mid+1;k<j;++k)
        t.Add(a[k].val,-1);
}
void solve(){
    ll ans=0;
    for(int i=1;i<=n;++i){
        ans+=t.Sum(n)-t.Sum(a[i].val);
        t.Add(a[i].val,1);
    }
    memset(t.t,0,sizeof(t.t));
    CDQ(1,n);
    sort(a+1,a+1+n);
    while(a[n].tim!=INF){
        cout<<ans<<'\n';
        ans-=a[n--].ans;
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) 
        cin>>a[i].val,a[i].pos=i,pos[a[i].val]=i,a[i].tim=INF;
    int u;
    for(int i=1;i<=m;++i) 
        cin>>u,a[pos[u]].tim=i;
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