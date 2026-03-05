#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
int tr[maxn],b[maxn];
struct node{
    int a,b;
    bool operator<(const node &x){
        return x.a>a;
    }
}a[maxn];

void add(int x,int k){
    while(x<=m) tr[x]+=k,x+=lowbit(x);
}
int query(int x){
    int ans=0;
    while(x) ans+=tr[x],x-=lowbit(x);
    return ans;
}
ll ans;
void solve(){
    for(int i=1;i<=n;++i){
        ans+=query(m)-query(b[i]);
        add(b[i],1);
    }
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].a,a[i].b=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) 
        if(a[i].a==a[i-1].a&&i!=1)  b[a[i].b]=m;
        else b[a[i].b]=++m;
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