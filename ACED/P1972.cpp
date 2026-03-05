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
int a[maxn],fr[maxn],idx;

inline void read(int &x){
    int f=1;x=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
}

int Blen;
struct Que{
    int l,r,id;
    inline bool operator<(Que x){
        if(l/Blen!=x.l/Blen) return l<x.l;
        return (l/Blen & 1) ? r<x.r : r>x.r;
    }
}q[maxn];
int cnt[maxn],ans[maxn],res;

inline void Add(int x){
    if(!(cnt[x]++)) res++;
}
inline void Del(int x){
    if(!(--cnt[x])) res--;
}

void solve(){
    int l=0,r=0;
    for(int i=1;i<=m;++i){
        while(r<q[i].r) Add(a[++r]);
        while(l>q[i].l) Add(a[--l]);
        while(r>q[i].r) Del(a[r--]);
        while(l<q[i].l) Del(a[l++]);
        ans[q[i].id]=res;
    }
    for(int i=1;i<=m;++i) 
        printf("%d\n",ans[i]);
}

void init(){
    read(n);
    Blen=sqrt(n);
    for(int i=1;i<=n;++i) {
        read(a[i]);
        if(!fr[a[i]]) fr[a[i]]=++idx;
        a[i]=fr[a[i]];
    }
    read(m);
    for(int i=1;i<=m;++i)
        read(q[i].l),read(q[i].r),q[i].id=i;
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