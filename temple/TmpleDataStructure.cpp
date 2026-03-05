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
int a[maxn];

struct Tag{
    Tag(){}
    bool operator==(const Tag &x)const{return 1;}
    Tag operator+(const Tag &x){}
};
struct Info{
    Info(){}
    Info operator+(const Info &x)const{}
    Info operator+(const Tag &x)const{}
};

struct Trie01{
    struct Node{
        int ch[2],val;
    }t[maxn];
#define ch(p) t[p].ch
#define val(p) t[p].val
    int idx=1;
    void Add(int x,int k){
        int p=1;
        for(int i=30;i>=0;--i){
            bool bi=(x>>i)&1;
            if(!ch(p)[bi]) ch(p)[bi]=++idx;
            p=ch(p)[bi],val(p)+=k;
        }
    }
    int Query(int x){
        int p=1,ans=0;
        for(int i=30;i>=0;--i){
            bool bi=(x>>i)&1;
            if(val(ch(p)[bi^1])>=1) 
                ans+=(1<<i),p=ch(p)[bi^1];
            else p=ch(p)[bi];
        }
        return ans;
    }
    void Init(){
        for(int i=1;i<=idx;++i)
            ch(i)[0]=ch(i)[1]=0,val(i)=0;
        idx=1;
    }
};

struct STtable{
    ll mia[maxn][25];
    ll GetMin(ll l,ll r){
        ll dif=r-l+1,ans=INF;
        for(ll i=20;i>=0;--i) if((dif>>i)&1)
            ans=min(mia[l][i],ans),l+=1<<i;
        return ans;
    }
    void Init(){
        for(ll k=1;k<=20;++k) for(ll i=1;i<=n;++i)
            mia[i][k]=min(mia[i+(1<<(k-1))][k-1],mia[i][k-1]);
    }
};

struct FHQTreap2{
    struct Node{
        int ls,rs;
        ll val,pri,len,siz;
    }t[maxn<<1];
    int rt,idx;
    mt19937 mt;
    stack<int>s;
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define val(p) t[p].val
#define mx(p) t[p].mx
#define tag(p) t[p].tag
#define pri(p) t[p].pri
#define len(p) t[p].len
#define siz(p) t[p].siz
    void PushUp(int p);
    void AddTag(int p,ll k);
    void PushDown(int p);
    int NewNode(ll val,int len){
        int id;
        if(s.size()) id=s.top(),s.pop();
        else id=++idx;
        t[id]={0,0,val,(int)mt(),len,len};
        return id;
    }
    pair<int,int> SplitNode(int p,int sz){
        int p2=NewNode(val(p),len(p)-sz);
        len(p)=sz;
        rs(p2)=rs(p),rs(p)=0;
        PushUp(p),PushUp(p2);
        return {p,p2};
    }
    void SplitS(int p,int sz,int &l,int &r){
        if(!p) return l=r=0,void();
        PushDown(p);
        if(siz(ls(p))>=sz){
            r=p;
            SplitS(ls(p),sz,l,ls(p));
        }else if(siz(ls(p))+len(p)<=sz){
            l=p;
            SplitS(rs(p),sz-siz(ls(p))-len(p),rs(p),r);
        }else{
            auto [p1,p2]=SplitNode(p,sz-siz(ls(p)));
            l=p1,r=p2;
        }PushUp(p);
    }
    int Merge(int l,int r){
        if(!l||!r) return l|r;
        if(pri(l)>pri(r)){
            PushDown(l);
            rs(l)=Merge(rs(l),r);
            PushUp(l);
            return l;
        }else{
            PushDown(r);
            ls(r)=Merge(l,ls(r));
            PushUp(r);
            return r;
        }
    }
    queue<int>q;
    void Del(int p){
        q.push(p);
        while(!q.empty()){
            p=q.front();q.pop();
            if(!p) continue;
            s.push(p);
            q.push(ls(p));
            q.push(rs(p));
        }
    }
    void Fun(int l,int r){
        int L,p,R;
        SplitS(rt,l-1,L,p);
        SplitS(p,r-l+1,p,R);
        //
        rt=Merge(L,Merge(p,R));
    }
    void Init(){
    }
};

struct FHQTreap{
    struct Node{
        int ls,rs,pri,siz;
        Info val,sum;
        Tag tag;
    }t[maxn<<1];
    int rt,idx;
    mt19937 mt;
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define val(p) t[p].val
#define sum(p) t[p].sum
#define tag(p) t[p].tag
#define pri(p) t[p].pri
#define siz(p) t[p].siz
    void PushUp(int p){
        sum(p)=sum(ls(p))+val(p)+sum(rs(p));
        siz(p)=siz(ls(p))+siz(rs(p))+1;
    }
    void AddTag(int p,Tag k){
        val(p)=val(p)+k,sum(p)=sum(p)+k;
        tag(p)=tag(p)+k;
    }
    void PushDown(int p){
        if(tag(p)==Tag{}) return;
        AddTag(ls(p),tag(p)),AddTag(rs(p),tag(p));
        tag(p)={};
    }
    int NewNode(Info val){
        t[++idx]={0,0,int(mt()),1,val,val,{}};
        return idx;
    }
    void SplitS(int p,int sz,int &l,int &r){
        if(!p) return l=r=0,void();
        PushDown(p);
        if(siz(ls(p))+1<=sz){
            l=p;
            SplitS(rs(p),sz-siz(ls(p))-1,rs(p),r);
        }else{
            r=p;
            SplitS(ls(p),sz,l,ls(p));
        }PushUp(p);
    }
    int Merge(int l,int r){
        if(!l||!r) return l|r;
        if(pri(l)>pri(r)){
            PushDown(l);
            rs(l)=Merge(rs(l),r);
            PushUp(l);
            return l;
        }else{
            PushDown(r);
            ls(r)=Merge(l,ls(r));
            PushUp(r);
            return r;
        }
    }
    Info Query(int l,int r){
        int L,p,R;
        SplitS(rt,l-1,L,p);
        SplitS(p,r-l+1,p,R);
        Info ans=sum(p);
        rt=Merge(L,Merge(p,R));
        return ans;
    }
    void Add(int l,int r,Tag k){
        int L,p,R;
        SplitS(rt,l-1,L,p);
        SplitS(p,r-l+1,p,R);
        AddTag(p,k);
        rt=Merge(L,Merge(p,R));
    }
    void Init(){
        sum(0)=val(0)={};
        tag(0)={};
    }
};

struct SegTree{
    struct Node{
        Info sum;
        Tag tag;
    }t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define sum(p) t[p].sum
#define tag(p) t[p].tag
    void AddTag(int p,Tag k){
        tag(p)=tag(p)+k;
        sum(p)=sum(p)+k;
    }
    void PushDown(int p){
        if(tag(p)==Tag()) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)={};
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Add(int p,int l,int r,int L,int R,Tag k){
        if(L<=l&&R>=r) return AddTag(p,k);
        if(l>R||r<L) return;
        PushDown(p);
        int mid=l+r>>1;
        Add(ls(p),l,mid,L,R,k);
        Add(rs(p),mid+1,r,L,R,k);
        PushUp(p);
    }
    void Change(int p,int l,int r,int x,Info k){
        if(l==r) return sum(p)=k,void();
        PushDown(p);
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    Info Query(int p,int l,int r,int L,int R){
        if(L<=l&&R>=r) return sum(p);
        if(l>R||r<L) return {};
        PushDown(p);
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    void Add(int l,int r,Tag k){
        Add(1,1,n,l,r,k);
    }
    Info Query(int l,int r){
        return Query(1,1,n,l,r);
    }
    void Build(int p,int l,int r){
        sum(p)={},tag(p)={};
        if(l==r) return sum(p)={},void();
        int mid=l+r>>1;
        Build(ls(p),l,mid);
        Build(rs(p),mid+1,r);
        PushUp(p);
    }
};

struct BitTree2{
    unordered_map<int,int>t[maxn];
#define lowbit(x) (x&(-x))
    void Add(int x,int y,int k){
        while(x<=n){
            for(int i=y;i<=n;i+=lowbit(i)) 
                t[x][i]+=k;
            x+=lowbit(x);
        }
    }
    int Query(int x,int y){
        int ans=0;
        while(x){
            for(int i=y;i;i-=lowbit(i)) 
                ans+=t[x][i];
            x-=lowbit(x);
        }
        return ans;
    }
};

struct LCT{
    struct Node{
        int ch[2],rev,fa;
        Info val,sum;
        Tag tag;
    }t[maxn];
#define ls(p) t[p].ch[0]
#define rs(p) t[p].ch[1]
#define ch(p) t[p].ch
#define val(p) t[p].val
#define sum(p) t[p].sum
#define rev(p) t[p].rev
#define tag(p) t[p].tag
#define fa(p) t[p].fa
    int idx,rt;
    void Rev(int p){
        swap(rs(p),ls(p));
        rev(p)^=1;
    }
    int NewNode(Info val){
        t[++idx]={0,0,0,0,val,val,{}};
        return idx;
    }
    void AddTag(int p,Tag k){
        sum(p)=sum(p)+k,val(p)=val(p)+k;
        tag(p)=tag(p)+k;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+val(p)+sum(rs(p));
    }
    void PushDown(int p){
        if(rev(p)) Rev(ls(p)),Rev(rs(p)),rev(p)=0;
        if(tag(p)==Tag()) return;
        AddTag(ls(p),tag(p)),AddTag(rs(p),tag(p));
        tag(p)={};
    }
    void PushAll(int p){
        if(!IsRoot(p)) PushAll(fa(p));
        PushDown(p);
    }
    bool IsRoot(int p){
        return ls(fa(p))!=p&&rs(fa(p))!=p;
    }
    void Rotate(int p){
        int fp=fa(p),ffp=fa(fp),k=rs(fp)==p;
        if(!IsRoot(fp)){
            ch(ffp)[rs(ffp)==fp]=p;
        }fa(p)=ffp;
        ch(fp)[k]=ch(p)[k^1],fa(ch(p)[k^1])=fp;
        ch(p)[k^1]=fp,fa(fp)=p;
        PushUp(fp),PushUp(p);
    }
    void Splay(int p){
        PushAll(p);
        while(!IsRoot(p)){
            int fp=fa(p),ffp=fa(fp);
            if(!IsRoot(fp)) 
                Rotate((ls(fp)==p)^(ls(ffp)==fp)?p:fp);
            Rotate(p);
        }
    }
    void Access(int p){
        for(int sp=0;p;sp=p,p=fa(p)){
            Splay(p);
            rs(p)=sp;
            PushUp(p);
        }
    }
    void MakeRoot(int p){
        Access(p);
        Splay(p);
        Rev(p);
    }
    int FindRoot(int p){
        Access(p);
        Splay(p);
        while(ls(p)) 
            PushDown(p),p=ls(p);
        Splay(p);
        return p;
    }
    void Link(int u,int v){
        MakeRoot(u);
        if(FindRoot(v)!=u)
            fa(u)=v;
    }
    void Cut(int u,int v){
        MakeRoot(u);
        Access(v);
        Splay(v);
        if(ls(v)==u&&!rs(u)&&fa(u)==v)
            ls(v)=fa(u)=0;
        PushUp(v);
    }
    Info Query(int u,int v){
        MakeRoot(u);
        Access(v);
        Splay(v);
        return sum(v);
    }
    void Add(int u,int v,Tag k){
        MakeRoot(u);
        Access(v);
        Splay(v);
        AddTag(v,k);
    }
    void Init(){
        val(0)=sum(0)={};
        tag(0)={};
    }
};

void solve(){
    
}

void init(){
    
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