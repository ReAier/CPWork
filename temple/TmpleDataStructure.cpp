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
    void reverse(){}
    Info operator+(const Info &x)const{}
    Info operator-(const Info &x)const{}
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

struct Dkt{
    int st[maxn],top;
    int a[maxn],ls[maxn],rs[maxn];
    void Build(){
        for(int i=1;i<=n;++i){
            int cur=top;
            while(cur&&a[st[cur]]>a[i]) 
                --cur;
            if(cur) rs[st[cur]]=i;
            if(cur<top) ls[i]=st[cur+1];
            top=cur;
            st[++top]=i;
        }
    }
};

struct STtable{
    ll mxa[maxn][25];
    ll Log2[maxn];
    ll GetMax(ll l,ll r){
        ll dif=Log2[r-l+1];
        return max(mxa[l][dif],mxa[r-(1<<dif)+1][dif]);
    }
    void Init(){
        for(ll k=1;k<=20;++k) for(ll i=1;i<=n;++i)
            mxa[i][k]=max(mxa[i+(1<<(k-1))][k-1],mxa[i][k-1]);
        Log2[1]=0;
        for(int i=2;i<=n;++i)
            Log2[i]=Log2[i/2]+1;
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

struct DSegTree{
    int root[maxn],idx;
    struct Node{
        int ls,rs,sum;
    }t[maxn<<5];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define sum(p) t[p].sum
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Change(int &p,int l,int r,int x,int k){
        if(!p) p=++idx;
        if(l==r) return sum(p)+=k,void(); 
        int mid=l+r>>1;
        if(x<=mid) Change(ls(p),l,mid,x,k);
        else Change(rs(p),mid+1,r,x,k);
        PushUp(p);
    }
    int Query(int p,int l,int r,int L,int R){
        if(l>R||r<L||!p) return 0;
        if(L<=l&&R>=r) return sum(p);
        int mid=l+r>>1;
        return Query(ls(p),l,mid,L,R)+Query(rs(p),mid+1,r,L,R);
    }
    void Change(int u,int x,int k){
        Change(root[u],0,n,x,k);
    }
    int Query(int u,int x){
        return Query(root[u],0,n,0,x);
    }
};

struct CSegTree{
    struct node{
        int ls,rs,sum;
    }t[maxn<<4];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define sum(p) t[p].sum
    int root[maxn],idx;
    int CopyNode(int p){
        t[++idx]=t[p];
        return idx;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+sum(rs(p));
    }
    void Change(int &p,int l,int r,int k){
        p=CopyNode(p);
        if(l==r) return sum(p)++,void();
        int mid=l+r>>1;
        if(k<=mid) Change(ls(p),l,mid,k);
        else Change(rs(p),mid+1,r,k);
        PushUp(p);
    }
    int Query(int u,int v,int l,int r,int k){
        if(l==r) return l;
        int s=sum(ls(v))-sum(ls(u)),mid=l+r>>1;
        if(s>=k) return Query(ls(u),ls(v),l,mid,k);
        return Query(rs(u),rs(v),mid+1,r,k-s);
    }
    int Query(int l,int r,int k){
        return Query(root[l-1],root[r],1,n,k);
    }
    void Init(){
        for(int i=1;i<=n;++i){
            root[i]=root[i-1];
            Change(root[i],1,n,a[i]);
        }
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

// LCT + 维护子树，带逆元信息
// reverse 无交换律信息需要反转
// 路径修改和子树查询冲突，不要一起使用！
// 无逆元版本需要使用 multiset 维护，复杂度多个log
struct LCT{
    struct Node{
        int ch[2],rev,fa;
        Info val,sum;
        Tag tag;
        Info vsum,tsum;
    }t[maxn];
#define ls(p) t[p].ch[0]
#define rs(p) t[p].ch[1]
#define ch(p) t[p].ch
#define val(p) t[p].val
#define sum(p) t[p].sum
#define vsum(p) t[p].vsum
#define tsum(p) t[p].tsum
#define rev(p) t[p].rev
#define tag(p) t[p].tag
#define fa(p) t[p].fa
    int idx,rt;
    void Rev(int p){
        if(!p) return;
        swap(ls(p),rs(p));
        sum(p).reverse();
        rev(p)^=1;
    }
    int NewNode(Info val){
        t[++idx]={0,0,0,0,val,val,{},{},val};
        return idx;
    }
    void AddTag(int p,Tag k){
        if(!p) return;
        sum(p)=sum(p)+k;
        val(p)=val(p)+k;
        tag(p)=tag(p)+k;
    }
    void PushUp(int p){
        sum(p)=sum(ls(p))+val(p)+sum(rs(p));
        tsum(p)=tsum(ls(p))+val(p)+tsum(rs(p))+vsum(p);
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
            vsum(p)=vsum(p)+tsum(rs(p));
            vsum(p)=vsum(p)-tsum(sp);
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
        if(FindRoot(v)!=u){
            Access(v),Splay(v),fa(u)=v;
            vsum(v)=vsum(v)+tsum(u);
        }
        PushUp(v);
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
    Info QuerySub(int u,int rt){
        MakeRoot(rt);
        Access(u);
        Splay(u);
        return val(u)+vsum(u);
    }
    void Change(int u,Info k){
        Access(u);
        Splay(u);
        val(u)=k;
        PushUp(u);
    }
    void Add(int u,int v,Tag k){
        MakeRoot(u);
        Access(v);
        Splay(v);
        AddTag(v,k);
    }
    void Init(){
        val(0)=sum(0)={};
        vsum(0)=tsum(0)={};
        tag(0)={};
    }
};

struct Tree{
    vector<int>e[maxn];
    int dep[maxn],fa[maxn],son[maxn],siz[maxn],top[maxn];
    void Dfs1(int u,int f){
        dep[u]=dep[fa[u]=f]+(siz[u]=1);
        for(int v:e[u]) if(v!=f){
            Dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
    void Dfs2(int u,int tp){
        top[u]=tp;
        if(!son[u]) return;
        Dfs2(son[u],tp);
        for(int v:e[u]) if(v!=fa[u]&&v!=son[u])
            Dfs2(v,v);
    }
    int GetLCA(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])
                swap(u,v);
            u=fa[top[u]];
        }
        return dep[u]>dep[v]?v:u;
    }
    int GetDis(int u,int v){
        int lca=GetLCA(u,v);
        return dep[u]+dep[v]-2*dep[lca];
    }
    void Init(){
        Dfs1(1,0);
        Dfs2(1,1);
    }
};

namespace TopTree{
    const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
    int n,m;
    int a[maxn];
    vector<int>e[maxn];
    int siz[maxn],son[maxn],fa[maxn];
    struct Info{
        int M[2][2];
        Info(int val=-INF){
            M[0][0]=M[0][1]=0;
            M[1][0]=val,M[1][1]=-INF;
        }
        int *operator[](const int x){
            return M[x];
        }
    };
    Info Compress(Info &u,Info &v){
        Info res;
        res[0][0]=max(v[0][0]+u[0][0],v[0][1]+u[1][0]);
        res[0][1]=max(v[0][0]+u[0][1],v[0][1]+u[1][1]);
        res[1][0]=max(v[1][0]+u[0][0],v[1][1]+u[1][0]);
        res[1][1]=max(v[1][0]+u[0][1],v[1][1]+u[1][1]);
        return res;
    }
    Info Rake(Info &u,Info &v){
        Info res;
        res[0][0]=u[0][0]+max(v[0][0],v[1][0]);
        res[0][1]=u[0][1]+max(v[0][1],v[1][1]);
        res[1][0]=u[1][0]+max(v[0][0],v[1][0]);
        res[1][1]=u[1][1]+max(v[0][1],v[1][1]);
        return res;
    }
    struct TopTree{
        struct Node{
            int ls,rs,fa;
            Info val;
            bool ty;
            int siz;
        }t[maxn];
    #define ls(p) t[p].ls
    #define rs(p) t[p].rs
    #define fa(p) t[p].fa
    #define val(p) t[p].val
    #define siz(p) t[p].siz
    #define ty(p) t[p].ty
        int idx,rt;
        int NewNode(bool ty,int val=-INF){
            t[++idx]={0,0,0,{val},ty,1};
            return idx;
        }
        void PushUp(int p){
            siz(p)=siz(ls(p))+siz(rs(p));
            val(p)=(ty(p)?Rake:Compress)(val(ls(p)),val(rs(p)));
        }
        int Merge(int u,int v,bool ty){
            int p=NewNode(ty);
            fa(ls(p)=u)=fa(rs(p)=v)=p;
            PushUp(p);
            return p;
        }
        int SubBuild(vector<int>&C,int l,int r,bool ty){
            if(l==r) return C[l];
            int sum=0,now=0;
            for(int i=l;i<=r;++i)
                sum+=siz(C[i]);
            for(int i=l;i<r;++i) if((now+=siz(C[i]))*2>=sum||i==r-1)
                return Merge(SubBuild(C,l,i,ty),SubBuild(C,i+1,r,ty),ty);
        }
        int Build(int p){
            vector<int>H;
            if(p<=n) H.push_back(p);
            for(int u=p;son[u];u=son[u]){
                vector<int>L;
                for(int v:e[u]) if(v^fa[u]&&v^son[u]) 
                    L.push_back(Build(v));
                if(!L.size()) H.push_back(son[u]);
                else H.push_back(Merge(son[u],SubBuild(L,0,L.size()-1,1),1));
            }
            return SubBuild(H,0,H.size()-1,0);
        }
        void Change(int u,int k){
            val(u)={k};
            while(u=fa(u)) PushUp(u); 
        }
        int Query(){
            return max(val(rt)[0][0],val(rt)[1][0]);
        }
        void Init(){
            for(int i=1;i<=n;++i)
                NewNode(0,a[i]);
            rt=Build(n+1);
        }
    }t;
    void Dfs(int u,int p){
        siz[u]=1,fa[u]=p;
        for(int v:e[u]) if(v^p)
            Dfs(v,u),siz[u]+=siz[v],siz[v]>siz[son[u]]?son[u]=v:0;
    }
    void solve(){
        int u,w;
        while(m--){
            cin>>u>>w;
            t.Change(u,w);
            cout<<t.Query()<<'\n';
        }
    }
    void init(){
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        int u,v;
        for(int i=1;i<n;++i)
            cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
        e[n+1].push_back(1),e[1].push_back(n+1);
        Dfs(n+1,0);
        t.Init();
    }
} // namespace TopTree

namespace NodeDivide{
    vector<pair<int,int>>e[maxn];
    int rt;
    int siz[maxn],mxp[maxn];
    bool vis[maxn];
    void GetRT(int u,int fa,int tot){
        siz[u]=1,mxp[u]=0;
        for(auto[v,w]:e[u])if(v!=fa&&!vis[v])
            GetRT(v,u,tot),siz[u]+=siz[v],mxp[u]=max(mxp[u],siz[v]);
        mxp[u]=max(mxp[u],tot-siz[u]);
        if(mxp[u]<mxp[rt]) rt=u;
    }
    struct BIT{
        int t[int(2e4)+100];
        void Add(int x,int k){
            x++;
            while(x<=m+10)
                t[x]+=k,x+=lowbit(x);
        }
        int Query(int x){
            x++;
            if(x>m+10) x=m+10;
            int ans=0;
            while(x)
                ans+=t[x],x-=lowbit(x);
            return ans;
        }
    }t; 
    
    int dis[maxn];
    vector<int>d,st;
    void Dfs(int u,int fa){
        d.push_back(dis[u]);
        for(auto[v,w]:e[u]) if(v!=fa&&!vis[v])
            dis[v]=dis[u]+w,Dfs(v,u);
    }
    ll ans=0;
    void Calc(int u){
        for(auto[v,w]:e[u])if(!vis[v]){
            dis[v]=w;
            d.clear();
            Dfs(v,u);
            for(int k:d) if(k<=m)
                ans+=t.Query(m-k);
            for(int k:d) if(k<=m)
                t.Add(k,1),st.push_back(k);
        }
        for(int k:st) t.Add(k,-1);
        st.clear();
    }
    void Divide(int u){
        Calc(u);
        vis[u]=1;
        for(auto[v,w]:e[u]) if(!vis[v]){
            rt=0;
            GetRT(v,u,siz[v]);
            Divide(rt);
        }
    }
    
    void solve(){
        GetRT(1,0,n);
        Divide(rt);
        cout<<ans<<'\n';
    }
    
    void init(){
        cin>>n;
        int u,v,w;
        for(int i=1;i<n;++i)
            cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
        cin>>m;
        t.Add(0,1);
        mxp[0]=INF;
    }
    
}

namespace CenTree{
    int a[maxn];
    vector<int>e[maxn];
    struct CenTree{
        int siz[maxn],mxp[maxn],cen,fa[maxn];
        bitset<maxn>vis;
        Tree lca;
        DSegTree t,f;
        int w[maxn];
        void GetCen(int u,int fa,int tot){
            siz[u]=1,mxp[u]=0;
            for(int v:e[u]) if(v!=fa&&!vis[v])
                GetCen(v,u,tot),siz[u]+=siz[v],mxp[u]=max(mxp[u],siz[v]);
            mxp[u]=max(mxp[u],tot-siz[u]);
            if(!cen||mxp[u]<mxp[cen]) cen=u;
        }
        void Build(int u,int tot){
            vis[u]=1;
            for(int v:e[u])if(!vis[v]){
                cen=0;
                tot=siz[v];
                GetCen(v,u,tot);
                fa[cen]=u;
                Build(cen,tot);
            }
        }
        void Change(int u,ll k){
            int now=u;
            while(now){
                t.Change(now,lca.GetDis(u,now),k-w[u]);
                if(fa[now]) f.Change(now,lca.GetDis(u,fa[now]),k-w[u]);
                now=fa[now];
            }
            w[u]=k;
        }
        ll Query(int u,int k){
            ll ans=0,now=u,pre=0;
            while(now){
                int dis=lca.GetDis(now,u);
                if(dis<=k){
                    ans+=t.Query(now,k-dis);
                    if(pre) ans-=f.Query(pre,k-dis);
                }
                pre=now,now=fa[now];
            }
            return ans;
        }
        void Init(){
            lca.Init();
            GetCen(1,0,n);
            Build(cen,n);
            for(int i=1;i<=n;++i)
                Change(i,a[i]);
        }
    }t;
    void solve(){
        ll lastans=0,op,x,k;
        while(m--){
            cin>>op>>x>>k;
            x^=lastans,k^=lastans;
            if(op) t.Change(x,k);
            else cout<<(lastans=t.Query(x,k))<<'\n';
        }
    }
    void init(){
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        int u,v;
        for(int i=1;i<n;++i)
            cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
        t.Init();
    }
}

namespace C_Mo{
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
    int l=1,r=0,t;
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
        Blen=pow(n,0.7);
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
}

namespace Mo{
    struct BIT{
        int t[maxn];
        #define lowbit(x) (x&(-x))
        #define LOG 17
            void Add(int x,int k){
                while(x<=maxn){
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
        int l=1,r=0;
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
}

// 区间加，区间询问>=C
struct Block1{
    int a[maxn],c[maxn],tag[maxn];
    int Bnum,Blen;
    int b[maxn];
    void PushDown(int bi){
        if(!tag[bi]) return;
        for(int i=b[bi-1]+1;i<=b[bi];++i)
            a[i]+=tag[bi],c[i]+=tag[bi];
        tag[bi]=0;
    }
    // 重构
    void Make(int bi){
        PushDown(bi);
        for(int i=b[bi-1]+1;i<=b[bi];++i)
            c[i]=a[i];
        sort(c+b[bi-1]+1,c+b[bi]+1);
    }
    // 在 c 中查找 >= k 的元素个数
    int Find(int bi,int k){
        int l=b[bi-1]+1,r=b[bi];
        if(c[r]<k) return 0;
        while(l<r){
            int mid=l+r>>1;
            if(c[mid]>=k) r=mid;
            else l=mid+1;
        }
        return b[bi]-r+1;
    }
    int Query(int l,int r,int k){
        int ql=(l-1)/Blen+1,qr=min((r-1)/Blen+1,Bnum),ans=0;
        PushDown(ql);
        for(int i=l;i<=min(b[ql],r);++i)
            ans+=a[i]>=k;
        if(ql!=qr){
            PushDown(qr);
            for(int i=b[qr-1]+1;i<=r;++i)
                ans+=a[i]>=k;
        }
        for(int i=ql+1;i<qr;++i)
            ans+=Find(i,k-tag[i]);
        return ans;
    }
    void Add(int l,int r,int k){
        int ql=(l-1)/Blen+1,qr=min((r-1)/Blen+1,Bnum);
        for(int i=l;i<=min(b[ql],r);++i)
            a[i]+=k;
        Make(ql);
        if(ql!=qr){
            for(int i=b[qr-1]+1;i<=r;++i)
                a[i]+=k;
            Make(qr);
        }
        for(int i=ql+1;i<qr;++i)
            tag[i]+=k;
    }
    void init(){
        Blen=sqrt(n);
        Bnum=n/Blen+(Blen*Blen<n);
        for(int i=1;i<Bnum;++i)
            b[i]=i*Blen;
        b[Bnum]=n;
        for(int i=1;i<=Bnum;++i)
            Make(i);
    }
};


// 强制在线区间众数
namespace Block2{
    const int Blen=200;
    int a[maxn],s[maxn][Blen+10],p[Blen+10][Blen+10],Bnum;
    map<int,int>mp;
    int b[maxn],idx;
    int cnt[maxn],mx;
    
    vector<int>st;
    
    int Query(int l,int r){
        int ql=(l-1)/Blen+1,qr=min((r-1)/Blen+1,Bnum),ans=0;
        for(int i=l;i<=min(ql*Blen,r);++i){
            if(!cnt[a[i]])
                st.push_back(a[i]);
            cnt[a[i]]++;
        }
        if(ql!=qr) for(int i=(qr-1)*Blen+1;i<=r;++i){
            if(!cnt[a[i]])
                st.push_back(a[i]);
            cnt[a[i]]++;
        }
        if(ql+1<=qr-1&&!cnt[p[ql+1][qr-1]])
            st.push_back(p[ql+1][qr-1]);
        for(int u:st){
            int cntu=cnt[u]+max(0,s[u][qr-1]-s[u][ql]);
            int cntv=cnt[ans]+max(0,s[ans][qr-1]-s[ans][ql]);
            if(cntu>cntv||(cntu==cntv&&u<ans))
                ans=u;
        }
        for(int u:st)
            cnt[u]=0;
        st.clear();
        return b[ans];
    }
    
    void solve(){
        memset(cnt,0,sizeof(cnt));
        int l,r,lastans=0;
        while(m--){
            cin>>l>>r;
            l=(l+lastans-1)%n;
            r=(r+lastans-1)%n;
            if(l>r) swap(l,r);
            cout<<(lastans=Query(l+1,r+1))<<'\n';
        }
    }
    int c[maxn];
    void init(){
        cin>>n>>m;
        Bnum=n/Blen+bool(n%Blen);
        for(int i=1;i<=n;++i)
            cin>>a[i],c[i]=a[i];
        sort(c+1,c+1+n);
        for(int i=1;i<=n;++i) if(!mp[c[i]]) 
            mp[c[i]]=++idx,b[idx]=c[i];
        for(int i=1;i<=n;++i)
            a[i]=mp[a[i]];
    
        for(int i=1;i<=Bnum;++i){
            for(int j=1;j<=idx;++j)
                s[j][i]+=s[j][i-1];
            for(int j=(i-1)*Blen+1;j<=min(n,i*Blen);++j)
                s[a[j]][i]++;
        }
    
        for(int i=1;i<=Bnum;++i) {
            memset(cnt,0,sizeof(cnt));
            for(int j=i;j<=Bnum;++j) {
                for(int k=(j-1)*Blen+1;k<=min(n,j*Blen);++k) {
                    cnt[a[k]]++;
                    if(cnt[a[k]]>cnt[mx]||(cnt[a[k]]==cnt[mx]&&a[k]<mx))
                        mx=a[k];
                }
                p[i][j]=mx;
            }
        }
    }
}

// 可撤销并查集
struct Dsu{
    int fa[maxn],siz[maxn];
    stack<pair<int,int>>s;
    void Init(){
        for(int i=1;i<=n;++i)
            fa[i]=i,siz[i]=1;
    }
    int Find(int x){
        while(x!=fa[x]) x=fa[x];
        return x;
    }
    void Merge(int u,int v){
        u=Find(u),v=Find(v);
        if(u==v) return s.push({0,0});
        if(siz[u]<siz[v]) swap(u,v);
        fa[v]=u;
        siz[u]+=siz[v];
        s.push({v,siz[v]});
    }
    void Undo(int k){
        while(k--){
            auto [v,sz]=s.top();s.pop();
            int u=fa[v];
            siz[u]-=sz;
            fa[v]=v;
        }
    }
};

// 线段树分治，离线动态图联通性
namespace SegTreeDivide{
    pair<int,int>Qu[maxn];
    int ans[maxn];
    Dsu s;
    struct SegTree{
        struct Node{
            vector<pair<int,int>>edg;
        }t[maxn<<2];
    #define ls(p) (p<<1)
    #define rs(p) (p<<1|1)
    #define edg(p) t[p].edg
        void Insert(int p,int l,int r,int L,int R,pair<int,int> k){
            if(L<=l&&R>=r) 
                return edg(p).push_back(k);
            if(l>R||r<L) return;
            int mid=l+r>>1;
            Insert(ls(p),l,mid,L,R,k);
            Insert(rs(p),mid+1,r,L,R,k);
        }
        void Dfs(int p,int l,int r){
            for(auto [u,v]:edg(p))
                s.Merge(u,v);
            if(l==r){
                auto [u,v]=Qu[l];
                if(u&&v) ans[l]=s.Find(u)==s.Find(v);
                else ans[l]=-1;
            }else{
                int mid=l+r>>1;
                Dfs(ls(p),l,mid);
                Dfs(rs(p),mid+1,r);
            }s.Undo(edg(p).size());
        }
        void Insert(int l,int r,pair<int,int>k){
            Insert(1,1,m,l,r,k);
        }
    }t;
    void solve(){
        t.Dfs(1,1,m);
        for(int i=1;i<=m;++i) if(~ans[i])
            cout<<(ans[i]?'Y':'N')<<'\n';
    }
    map<pair<int,int>,int>mp;
    void init(){
        cin>>n>>m;
        int op,u,v;
        for(int i=1;i<=m;++i){
            cin>>op>>u>>v;
            if(u>v) swap(u,v);
            if(op==1) {
                t.Insert(mp[{u,v}],i-1,{u,v});
                mp.erase({u,v});
            }else if(!op)
                mp[{u,v}]=i;
            else Qu[i]={u,v};
        }
        for(auto [e,l]:mp)
            t.Insert(l,m,e);
        s.Init();
    }
}

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