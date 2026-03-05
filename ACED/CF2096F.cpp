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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m,q;
struct SegTree{
    struct Node{
        int mi,ad;
    }t[maxn];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mi(p) t[p].mi
#define ad(p) t[p].ad
    void AddTag(int p,int k){
        ad(p)+=k;
        mi(p)+=k;
    }
    void PushUp(int p){
        mi(p)=min(mi(ls(p)),mi(rs(p)));
    }
    void PushDown(int p){
        if(!ad(p)) return;
        AddTag(ls(p),ad(p));
        AddTag(rs(p),ad(p));
        ad(p)=0;
    }
    void Change(int p,int l,int r,int L,int R,int k){
        if(L<=l&&R>=r) 
            return AddTag(p,k);
        if(L>r||R<l) 
            return;
        PushDown(p);
        int mid=l+r>>1;
        Change(ls(p),l,mid,L,R,k);
        Change(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    int Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) 
            return mi(p);
        if(L>r||R<l)
            return INF;
        PushDown(p);
        int mid=l+r>>1;
        return min(Query(ls(p),l,mid,L,R),Query(rs(p),mid+1,r,L,R));
    }
    int QueryS(int p,int l,int r,int L,int R,bool k){
        if(L>r||R<l||mi(p)) return -1;
        if(l==r) return l;
        PushDown(p);
        int mid=l+r>>1,res;
        if(k){
            res=QueryS(ls(p),l,mid,L,R,k);
            if(~res) return res;
            return QueryS(rs(p),mid+1,r,L,R,k);
        }else {
            res=QueryS(rs(p),mid+1,r,L,R,k);
            if(~res) return res;
            return QueryS(ls(p),l,mid,L,R,k);
        }
    }
    pii QueryS(int l,int r){
        l=QueryS(1,1,n,1,l,0);
        r=QueryS(1,1,n,r,n,1);
        if(!(~l)) l=0;
        if(!(~r)) r=n+1;
        return {l+1,r-1};
    }
    void Build(int p,int l,int r){
        ad(p)=mi(p)=0;
        if(l==r) return;
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Change(int l,int r,int k){
        Change(1,1,n,l,r,k);
    }
    int Query(int l,int r){
        return Query(1,1,n,l,r);
    }
}t1;
struct SegTree2{
    int mx[maxn];
    void Change(int p,int l,int r,int x,int k){
        if(l==r) return mx[p]=k,void();
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        mx[p]=max(mx[ls(p)],mx[rs(p)]);
    }
    int Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) 
            return mx[p];
        if(L>r||R<l)
            return 0;
        int mid=l+r>>1;
        return max(Query(ls(p),l,mid,L,R),Query(rs(p),mid+1,r,L,R));
    }
    void Change(int x,int k){
        Change(1,1,n,x,k);
    }
    int Query(int x){
        return Query(1,1,n,1,x);
    }
    void Init(){
        for(int i=1;i<=4*n;++i)
            mx[i]=0;
    }
}t2;
multiset<int>ms[maxn];

struct Sta{
    int op,l,r;
}a[maxn];
int mil[maxn];

void MoveL(int &x){
    auto [op,l,r]=a[x];
    if(op){
        ms[r].erase(ms[r].find(l));
        if(!ms[r].empty())
            t2.Change(r,*ms[r].rbegin());
        else t2.Change(r,0);
    }else t1.Change(l,r,-1);
    ++x;
}

void solve(){
    cin>>q;
    int l,r;
    while(q--){
        cin>>l>>r;
        if(l>=mil[r])
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
void init(){
    cin>>n>>m;
    t1.Build(1,1,n);
    t2.Init();
    for(int i=1;i<=n;++i)
        ms[i].clear();
    int L=1;
    for(int i=1;i<=m;++i){
        cin>>a[i].op>>a[i].l>>a[i].r;
        auto [op,l,r]=a[i];
        if(op){
            while(t1.Query(l,r)) 
                MoveL(L);
            ms[r].insert(l);
            t2.Change(r,*ms[r].rbegin());
        }else{
            t1.Change(l,r,1);
            while(1){
                auto [x,y]=t1.QueryS(l,r);
                if(t2.Query(y)<x) 
                    break;
                MoveL(L);
            }
        }
        mil[i]=L;
    }
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
    cin>>T;
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