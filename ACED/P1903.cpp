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
int Blen;
struct Query{
    int l,r,t,id;
    bool operator<(Query x){
        if(t/Blen!=x.t/Blen) return t>x.t;
        if(l/Blen!=x.l/Blen) return (t/Blen&1)? l<x.l:l>x.l;
        return (l/Blen&1)?r<x.r:r>x.r;
    }
}q[maxn];
struct Change{
    int pos,pre,now;
}c[maxn];
int l,r,t;
int a[maxn],m1,m2,ans[maxn];
int cnt[maxn],res;

void Add(int u){
    if(!(cnt[u]++)) res++;
}
void Del(int u){
    if(!(--cnt[u])) res--;
}
void Cha(int u,bool i){
    auto [pos,pre,now]=c[u];
    if(i){
        if(pos>=l&&pos<=r)
            Del(pre),Add(now);
        a[pos]=now;
    }else{
        if(pos>=l&&pos<=r)
            Del(now),Add(pre);
        a[pos]=pre;
    }
}
void solve(){
    t=m2;
    for(int i=1;i<=m1;++i){
        while(t<q[i].t) Cha(++t,1);
        while(t>q[i].t) Cha(t--,0);
        while(r<q[i].r) Add(a[++r]);
        while(l>q[i].l) Add(a[--l]);
        while(r>q[i].r) Del(a[r--]);
        while(l<q[i].l) Del(a[l++]);
        ans[q[i].id]=res;
    }
    for(int i=1;i<=m1;++i)
        cout<<ans[i]<<'\n';
}
void init(){
    cin>>n>>m;
    Blen=pow(n,0.67);
    for(int i=1;i<=n;++i) cin>>a[i];
    char ch;
    int u,v;
    while(m--){
        cin>>ch>>u>>v;
        if(ch=='Q') q[++m1]={u,v,m2,m1};
        else c[++m2]={u,a[u],v},a[u]=v;
    }
    sort(q+1,q+1+m1);
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