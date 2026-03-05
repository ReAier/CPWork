#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
#define OPEN_FILE
#define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const int maxn=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct BIT{
#define lowbit(x) (x&(-x))
#define LOG 17
    int t[maxn];
    void Add(int x,int k){
        while(x<=maxn ){
            t[x]+=k;
            x+=lowbit(x);
        }
    }
    int Query(){
        int pos=0,nx;
        for(int i=LOG;i>=0;--i){
            nx=pos+(1<<i);
            if(t[nx]==(1<<i))
                pos=nx;
        }
        return pos+1;
    }
}t;

int Blen;
struct Que{
    int l,r,id;
    bool operator<(Que x){
        if(l/Blen!=x.l/Blen) return l<x.l;
        return (r<x.r);
    }
}q[maxn];
int cnt[maxn],ans[maxn];

void Add(int x){
    if(!(cnt[x]++)) t.Add(x,1);
}
void Del(int x){
    if(!(--cnt[x])) t.Add(x,-1);
}

void solve(){
    int l=0,r=0;
    for(int i=1;i<=m;++i){
        while(r<q[i].r) Add(a[++r]);
        while(l>q[i].l) Add(a[--l]);
        while(r>q[i].r) Del(a[r--]);
        while(l<q[i].l) Del(a[l++]);
        ans[q[i].id]=t.Query()-1;
    }
    for(int i=1;i<=m;++i)   
        printf("%d\n",ans[i]);
}

void init(){
    cin>>n>>m;
    Blen=sqrt(n);
    for(int i=1;i<=n;++i)
        cin>>a[i],a[i]++;
    for(int i=1;i<=m;++i)
        cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m);
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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