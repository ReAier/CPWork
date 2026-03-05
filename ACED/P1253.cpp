#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct FHQTreap{
    struct Node{
        int ls,rs;
        ll val,mx,tag,pri,len,siz;
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
    void PushUp(int p){
        mx(p)=max(val(p),max(mx(ls(p)),mx(rs(p))));
        siz(p)=siz(ls(p))+siz(rs(p))+len(p);
    }
    void AddTag(int p,ll k){
        if(!p) return;
        tag(p)+=k;
        val(p)+=k;
        mx(p)+=k;
    }
    void PushDown(int p){
        if(!tag(p)) return;
        AddTag(ls(p),tag(p));
        AddTag(rs(p),tag(p));
        tag(p)=0;
    }
    int NewNode(ll val,int len){
        int id;
        if(s.size()) id=s.top(),s.pop();
        else id=++idx;
        t[id]={0,0,val,val,0,(int)mt(),len,len};
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
    void Cover(int l,int r,ll k){
        int L,p,R;
        SplitS(rt,l-1,L,p);
        SplitS(p,r-l+1,p,R);
        Del(p);
        rt=Merge(L,Merge(NewNode(k,r-l+1),R));
    }
    void Add(int l,int r,ll k){
        int L,p,R;
        SplitS(rt,l-1,L,p);
        SplitS(p,r-l+1,p,R);
        AddTag(p,k);
        rt=Merge(L,Merge(p,R));
    }
    void Print(int u){
        if(!u) return;
        PushDown(u);
        Print(ls(u));
        cout<<val(u)<<" ";
        Print(rs(u));
    }
    ll Query(int l,int r){
        int L,p,R;
        SplitS(rt,l-1,L,p);
        SplitS(p,r-l+1,p,R);
        ll ans=mx(p);
        rt=Merge(L,Merge(p,R));
        return ans;
    }
    void Init(){
        val(0)=mx(0)=-INF;
        for(int i=1;i<=n;++i)   
            rt=Merge(rt,NewNode(a[i],1));
    }
}t;


void solve(){
    int op,l,r,k;
    while(m--){
        cin>>op>>l>>r;
        if(op==1){
            cin>>k;
            t.Cover(l,r,k);
        }else if(op==2){
            cin>>k;
            t.Add(l,r,k);
        }else cout<<t.Query(l,r)<<'\n';
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
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