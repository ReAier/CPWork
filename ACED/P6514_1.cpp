#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Node{
    int opt,l,r,id,ans;
}a[maxn];
struct BitTree{
    int t[maxn];
#define lowbit(x) (x&(-x))
    void Add(int x,int k){
        while(x<=n)
            t[x]+=k,x+=lowbit(x);
    }
    int Query(int x){
        int ans=0;
        while(x)
            ans+=t[x],x-=lowbit(x);
        return ans;
    }
}t;
bool cmp(Node x,Node y){return x.r==y.r?x.l<y.l:x.r>y.r;}
void CDQ(int l,int r){
    if(l==r) return;
    int mid=l+r>>1;
    CDQ(l,mid),CDQ(mid+1,r);
    sort(a+l,a+mid+1,cmp);
    sort(a+mid+1,a+r+1,cmp);
    int i=l,j=mid+1;
    while(j<=r){
        while(a[i].r>=a[j].r&&i<=mid){
            if(a[i].opt==1) t.Add(a[i].l,1);
            ++i;
        }
        if(a[j].opt==2) a[j].ans+=t.Query(a[j].l);
        ++j;
    }
    for(int k=l;k<i;++k) if(a[k].opt==1)
        t.Add(a[k].l,-1);
}
void solve(){
    CDQ(1,m);
    sort(a+1,a+1+m,[](Node x,Node y){return x.id<y.id;});
    for(int i=1;i<=m;++i) if(a[i].opt==2) 
        cout<<a[i].ans<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=m;++i) 
        cin>>a[i].opt>>a[i].l>>a[i].r,a[i].id=i;
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