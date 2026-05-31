#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
mt19937_64 mt(1145);
ll n,m;
int a[maxn];
vector<int>pos[maxn];
struct Q{
    int l,r,k;
};
vector<Q>q[maxn];
struct SegTree{
    struct Node{
        int cnt,sum,len;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define cnt(p) t[p].cnt
#define sum(p) t[p].sum
#define len(p) t[p].len
    void PushUp(int p) { // 开大数组！
        if(cnt(p)>0) sum(p)=len(p);
        else sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Add(int p,int l,int r,int L,int R,int k) {
        if(L<=l&&R>=r) return cnt(p)+=k,PushUp(p);
        if(L>r||R<l) return;
        int mid=l+r>>1;
        Add(ls(p),l,mid,L,R,k);
        Add(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    void Add(int l,int r,int k) {
        Add(1,1,n,l,r,k);
    }
    int Query() {return sum(1);}
    void Build(int p,int l,int r) {
        len(p)=r-l+1;
        if(l==r) return;
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
    }
}t;

void solve() {
    ll ans=n*(n+1)/2ll;
    for(int i=1;i<=1e6;++i) {
        for(int j=1;j+m<pos[i].size();++j) {
            int l1=pos[i][j-1]+1,r1=pos[i][j];
            int l2=pos[i][j+m-1],r2=pos[i][j+m];
            q[l2].push_back({l1,r1,1});
            q[r2].push_back({l1,r1,-1});
        }
    }
    for(int i=1;i<=n;++i) {
        for(auto[l,r,k]:q[i])
            t.Add(l,r,k);
        ans-=t.Query();
    }
    cout<<ans<<'\n';
}
void init() {
    cin>>n>>m;
    for(int i=1;i<=1e6;++i)
        pos[i].push_back(0);
    for(int i=1;i<=n;++i)
        cin>>a[i],pos[a[i]].push_back(i);
    for(int i=1;i<=1e6;++i)
        pos[i].push_back(n+1);
    t.Build(1,1,n);
}
int main() {
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
    // while(cin>>n) {
    while(T--) {
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}