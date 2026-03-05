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
pair<int,int> a[maxn];
int b[maxn],Blen;
struct Query{
    int l,r,id;
    bool operator<(Query x){
        if(l/Blen!=x.l/Blen) return l<x.l;
        return (l/Blen)&1 ? r<x.r : r>x.r;
    }
}q[maxn];
int ans[maxn],cnt[maxn],res;

void Add(int x){
    if(cnt[b[x]]==2) --res;
    if(++cnt[b[x]]==2) ++res; 
}
void Del(int x){
    if(cnt[b[x]]==2) --res;
    if(--cnt[b[x]]==2) ++res;
}

void solve(){
    int l=0,r=0;
    for(int i=1;i<=m;++i){
        while(l>q[i].l) Add(--l);
        while(r<q[i].r) Add(++r);
        while(l<q[i].l) Del(l++);
        while(r>q[i].r) Del(r--);
        ans[q[i].id]=res;
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<"\n";
}

int idx;
void init(){
    cin>>n>>m;
    Blen=sqrt(n);
    a[0].first=-1;
    for(int i=1;i<=n;++i)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) {
        if(a[i].first!=a[i-1].first) ++idx;
        b[a[i].second]=idx;
    }
    for(int i=1;i<=m;++i)
        cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m);
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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