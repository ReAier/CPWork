#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
// #define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const ll maxn=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct SegTree{
    struct Node{
        ll mx1,mx2,hmx,sum,cnt,ad1,ad2,ad3,ad4,len;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mx1(p) t[p].mx1
#define mx2(p) t[p].mx2
#define hmx(p) t[p].hmx
#define sum(p) t[p].sum
#define cnt(p) t[p].cnt
#define ad1(p) t[p].ad1
#define ad2(p) t[p].ad2
#define ad3(p) t[p].ad3
#define ad4(p) t[p].ad4
#define len(p) t[p].len
    void AddTag(int p,ll k1,ll k2,ll k3,ll k4){
        sum(p)+=cnt(p)*k1+(len(p)-cnt(p))*k2;
        hmx(p)=max(hmx(p),mx1(p)+k3);
        mx1(p)+=k1;
        if(mx2(p)!=-INF) mx2(p)+=k2;
        ad3(p)=max(ad3(p),ad1(p)+k3),ad1(p)+=k1;
        ad4(p)=max(ad4(p),ad2(p)+k4),ad2(p)+=k2;
    }
    void MinTag(int p,ll k){
        ad1(p)-=mx1(p)-k;
        sum(p)-=(mx1(p)-k)*cnt(p);
        mx1(p)=k;
    }
    void PushDown(int p){
        if(!ad1(p)&&!ad2(p)&&!ad3(p)&&!ad4(p)) 
            return;
        int mx=max(mx1(ls(p)),mx1(rs(p)));
        if(mx1(ls(p))==mx)
            AddTag(ls(p),ad1(p),ad2(p),ad3(p),ad4(p));
        else AddTag(ls(p),ad2(p),ad2(p),ad4(p),ad4(p));
        if(mx1(rs(p))==mx)
            AddTag(rs(p),ad1(p),ad2(p),ad3(p),ad4(p));
        else AddTag(rs(p),ad2(p),ad2(p),ad4(p),ad4(p));
        ad1(p)=ad2(p)=ad3(p)=ad4(p)=0;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
        hmx(p)=max(hmx(ls(p)),hmx(rs(p)));
        if(mx1(ls(p))==mx1(rs(p))){
            mx1(p)=mx1(ls(p));
            cnt(p)=cnt(ls(p))+cnt(rs(p));
            mx2(p)=max(mx2(ls(p)),mx2(rs(p)));
        }else if(mx1(ls(p))>mx1(rs(p))){
            mx1(p)=mx1(ls(p));
            cnt(p)=cnt(ls(p));
            mx2(p)=max(mx2(ls(p)),mx1(rs(p)));
        }else{
            mx1(p)=mx1(rs(p));
            cnt(p)=cnt(rs(p));
            mx2(p)=max(mx1(ls(p)),mx2(rs(p)));
        }
    }
    void Add(int p,int l,int r,int L,int R,ll k){
        if(L<=l&&R>=r) return AddTag(p,k,k,k,k);
        if(L>r||R<l) return;
        PushDown(p);
        int mid=l+r>>1;
        Add(ls(p),l,mid,L,R,k);
        Add(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    void CKmin(int p,int l,int r,int L,int R,ll k){
        if(L<=l&&R>=r&&mx1(p)>k&&mx2(p)<k) 
            return MinTag(p,k);
        if(L>r||R<l||mx1(p)<k||l==r) return;
        PushDown(p);
        int mid=l+r>>1;
        CKmin(ls(p),l,mid,L,R,k);
        CKmin(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    ll QuerySum(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return sum(p);
        if(L>r||R<l) return 0;
        PushDown(p);
        int mid=l+r>>1;
        return QuerySum(ls(p),l,mid,L,R)+QuerySum(rs(p),mid+1,r,L,R);
    }
    ll QueryMax(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return mx1(p);
        if(L>r||R<l) return -INF;
        PushDown(p);
        int mid=l+r>>1;
        return max(QueryMax(ls(p),l,mid,L,R),QueryMax(rs(p),mid+1,r,L,R));
    }
    ll QueryHMax(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return hmx(p);
        if(L>r||R<l) return -INF;
        PushDown(p);
        int mid=l+r>>1;
        return max(QueryHMax(ls(p),l,mid,L,R),QueryHMax(rs(p),mid+1,r,L,R));
    }
    void Build(int p,int l,int r){
        if(l==r) return t[p]={a[l],-INF,a[l],a[l],1,0,0,0,0,1},void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
        len(p)=len(ls(p))+len(rs(p));
    }
}t;


void solve(){
    int op,l,r,k;
    while(m--){
        cin>>op>>l>>r;
        switch (op)
        {
        case 1:
            cin>>k;
            t.Add(1,1,n,l,r,k);
            break;
        case 2:
            cin>>k;
            t.CKmin(1,1,n,l,r,k);
            break;
        case 3:
            cout<<t.QuerySum(1,1,n,l,r)<<'\n';
            break;
        case 4:
            cout<<t.QueryMax(1,1,n,l,r)<<'\n';
            break;
        case 5:
            cout<<t.QueryHMax(1,1,n,l,r)<<'\n';
            break;
        }
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    t.Build(1,1,n);
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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