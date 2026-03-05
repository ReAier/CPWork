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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
double a[maxn];
struct SegTree{
    struct Tag{
        double k;
        Tag operator+(Tag x){
            return {k+x.k};
        }
        bool operator!(){
            return fabs(k)<eps;
        }
    };
    struct Info{
        double Sin,Cos;
        Info operator+(Info x){
            return {Sin+x.Sin,Cos+x.Cos};
        }
        Info operator+(Tag x){
            Info ans;
            ans.Sin=Sin*cos(x.k)+Cos*sin(x.k);
            ans.Cos=Cos*cos(x.k)-Sin*sin(x.k);
            return ans;
        }
    };
    struct Node{
        Info sum;
        Tag tag;
    }t[maxn];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define sum(p) t[p].sum
#define tag(p) t[p].tag
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void AddTag(int p,Tag k){
        tag(p)=tag(p)+k;
        sum(p)=sum(p)+k;
    }
    void PushDown(int p){
        if(!tag(p)) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)={0};
    }
    void Change(int p,int l,int r,int L,int R,Tag k){
        if(L<=l&&R>=r) return AddTag(p,k);
        if(L>r||R<l) return;
        int mid=l+r>>1;
        PushDown(p);
        Change(ls(p),l,mid,L,R,k);
        Change(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    Info Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return sum(p);
        if(L>r||R<l) return {0,0};
        int mid=l+r>>1;
        PushDown(p);
        return Query(ls(p),l,mid,L,R)
            +Query(rs(p),mid+1,r,L,R);
    }
    void Build(int p,int l,int r){
        if(l==r) return sum(p)={sin(a[l]),cos(a[l])},void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Change(int l,int r,double k){
        Change(1,1,n,l,r,{k});
    }
    double Query(int l,int r){
        return Query(1,1,n,l,r).Sin;
    }
}t;

void solve(){
    int op,l,r,k;
    while(m--){
        cin>>op>>l>>r;
        if(op==1){
            cin>>k;
            t.Change(l,r,k);
        }else printf("%.1f\n",t.Query(l,r));
    }
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    t.Build(1,1,n);
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