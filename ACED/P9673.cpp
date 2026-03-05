#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn],ans;
struct FhqTreap{
    struct Node{
        int ls,rs,val,mi,ma,pri,siz,id;
    }t[maxn];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define val(p) t[p].val
#define mi(p) t[p].mi
#define ma(p) t[p].ma
#define pri(p) t[p].pri
#define siz(p) t[p].siz
#define id(p) t[p].id
    int rt,idx;
    inline int NewNode(int val,int dep,int id){
        t[++idx]={0,0,val,val,val,dep,1,id};
        return idx;
    }
    inline void PushUp(int p){
        mi(p)=min(val(p),min(mi(ls(p)),mi(rs(p))));
        ma(p)=max(val(p),max(ma(ls(p)),ma(rs(p))));
        siz(p)=siz(ls(p))+siz(rs(p))+1;
    }
    int Merge(int l,int r){
        if(!l||!r) return l|r;
        if(pri(l)<pri(r)){
            rs(l)=Merge(rs(l),r);
            PushUp(l);
            return l;
        }else{
            ls(r)=Merge(l,ls(r));
            PushUp(r);
            return r;
        }
    }
    void Split(int p,int sz,int &l,int &r){
        if(!p) return l=r=0,void();
        if(siz(ls(p))+1<=sz){
            l=p;
            Split(rs(p),sz-siz(ls(p))-1,rs(p),r);
        }else{
            r=p;
            Split(ls(p),sz,l,ls(p));
        }
        PushUp(p);
    }
    inline void Change(int x,int k){
        int l,r,p;
        Split(rt,x-1,l,p);
        Split(p,1,p,r);
        t[p]={0,0,k,k,k,pri(p),1,id(p)};
        rt=Merge(l,Merge(p,r));
    }
    int FindL(int p,int k){
        if(ma(ls(p))>=k) return FindL(ls(p),k);
        if(val(p)>=k) return id(p);
        return FindL(rs(p),k);
    }
    inline int GetL(int L,int R,int k){
        int l,p,r;
        Split(rt,L-1,l,p);
        int res=FindL(p,k);
        rt=Merge(l,p);
        return res?res:R;
    }
    int FindR(int p,int k){
        if(mi(rs(p))<=k) return FindR(rs(p),k);
        if(val(p)<=k) return id(p);
        return FindR(ls(p),k);
    }
    inline int GetR(int L,int R,int k){
        int l,p,r;
        Split(rt,R,p,r);
        int res=FindR(p,k);
        rt=Merge(p,r);
        return res?res:L;
    }
    int Build(int l,int r,int dep){
        if(l>r) return 0;
        int mid=l+r>>1;
        int p=NewNode(a[mid],dep,mid);
        ls(p)=Build(l,mid-1,dep+1);
        rs(p)=Build(mid+1,r,dep+1);
        PushUp(p);
        return p;
    }
    inline void Init(){
        idx=0;
        t[0]={0,0,0,INF,-INF,0,0,0};
        rt=Build(1,n,1);
    }
}t;

int Partition(int l,int r){
    int p=a[l+r>>1];
    int i=l-1,j=r+1;
    while(1){
        i=t.GetL(i+1,r,p);
        j=t.GetR(l,j-1,p);
        if(i>=j) return j;
        swap(a[i],a[j]),++ans;
        t.Change(i,a[i]);
        t.Change(j,a[j]);
    }
}
void QuickSort(int l,int r){
    if(l>=1&&r>=1&&l<r){
        int p=Partition(l,r);
        QuickSort(l,p);
        QuickSort(p+1,r);
    }
}

void solve(){
    QuickSort(1,n);
    cout<<ans<<'\n';
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    ans=0;
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
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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