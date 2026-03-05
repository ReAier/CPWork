#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=6e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct SegTree{
    struct Tag{
        int k;
        Tag operator+(Tag x){return x;}
        bool operator!(){return !~k;}
    };
    struct Info{
        int per,suf,val,len;
        Info operator+(Info x){
            Info ans;
            ans.per=per==len?len+x.per:per;
            ans.suf=x.suf==x.len?x.len+suf:x.suf;
            ans.val=max({val,x.val,suf+x.per});
            ans.len=len+x.len;
            return ans;
        }
        Info operator+(Tag x){
            Info ans=*this;
            if(x.k) ans.val=ans.suf=ans.per=len;
            else ans.val=ans.suf=ans.per=0;
            return ans;
        }
    };
    struct Node{
        Tag tag;
        Info info;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define tag(p) t[p].tag
#define info(p) t[p].info
    void AddTag(int p,Tag k){
        tag(p)=tag(p)+k;
        info(p)=info(p)+k;
    }
    void PushDown(int p){
        if(!tag(p)) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)={-1};
    }
    void PushUp(int p){
        info(p)=info(ls(p))+info(rs(p));
    }
    void Change(int p,int l,int r,int L,int R,Tag k){
        if(L<=l&&R>=r) return AddTag(p,k);
        if(l>R||r<L) return;
        int mid=l+r>>1;
        PushDown(p);
        Change(ls(p),l,mid,L,R,k);
        Change(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    int Query(int p,int l,int r,int k){
        if(l==r) return l;
        int mid=l+r>>1,res;
        PushDown(p);
        if(info(ls(p)).val>=k)
            res= Query(ls(p),l,mid,k);
        else if(info(ls(p)).suf+info(rs(p)).per>=k)
            res=Query(rs(p),mid+1,r,k-info(ls(p)).suf);
        else res= Query(rs(p),mid+1,r,k);
        PushUp(p);
        return res;
    }
    void Change(int l,int r,bool k){
        Change(1,1,n,l,r,{k});
    }
    int Query(int k){
        return info(1).val>=k?Query(1,1,n,k)-k+1:0;
    }
    void Build(int p,int l,int r){
        tag(p)={-1};
        if(l==r) return info(p)={1,1,1,1},void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
    void Init(){Build(1,1,n);}
}t;


void solve(){
    int op,l,r;
    while(m--){
        cin>>op>>l;
        if(op==1){
            int L=t.Query(l);
            if(L) t.Change(L,L+l-1,0);
            cout<<L<<'\n';
        }else cin>>r,t.Change(l,l+r-1,1);
    }
}

void init(){
    cin>>n>>m;
    t.Init();
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