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

char buf[maxn<<4],*_s,*_t;
#define gc() (_s==_t && (_t=(_s=buf)+fread(buf,1,maxn<<4,stdin),_s==_t)?EOF:*_s++)
inline void read(int &x){
    int f=1;x=0;
    char ch=gc();
    for(;!isdigit(ch);ch=gc())
        if(ch=='-') f=-1;
    for(;isdigit(ch);ch=gc())
        x=x*10+ch-'0';
    x*=f;
}
char outBuf[1 << 20];
int outP = 0;
inline void flush() { 
    fwrite(outBuf, 1, outP, stdout); 
    outP = 0; 
}
inline void print(ll x) {
    if (x < 0) outBuf[outP++] = '-', x = -x;
    if (x == 0) { outBuf[outP++] = '0'; outBuf[outP++] = '\n'; return; }
    static int st[20]; 
    int top = 0;
    while (x) st[++top] = x % 10, x /= 10;
    while (top) outBuf[outP++] = st[top--] + '0';
    outBuf[outP++] = '\n';
    if (outP > (1 << 20) - 50) flush();
}
int mem[maxn<<5],used;

int n,m,B=400;
int a[maxn];
vector<int>e[maxn];
int siz[maxn],son[maxn],fa[maxn];
pii ql[maxn],qr[maxn],q[maxn];
struct Info {
    ll m00, m01, m10, m11;
    Info(ll val = -INF) {
        m00 = m01 = 0;
        m10 = val; m11 = -INF;
    }
};
#define max(u,v) (u>v?u:v)
inline void Compress(const Info &u, const Info &v, Info &res) {
    res.m00 = max(v.m00 + u.m00, v.m01 + u.m10);
    res.m01 = max(v.m00 + u.m01, v.m01 + u.m11);
    res.m10 = max(v.m10 + u.m00, v.m11 + u.m10);
    res.m11 = max(v.m10 + u.m01, v.m11 + u.m11);
}
inline void Rake(const Info &u, const Info &v, Info &res) {
    ll max_v0 = max(v.m00, v.m10);
    ll max_v1 = max(v.m01, v.m11);
    res.m00 = u.m00 + max_v0;
    res.m01 = u.m01 + max_v1;
    res.m10 = u.m10 + max_v0;
    res.m11 = u.m11 + max_v1;
}

int nx1[maxn],nx2[maxn],nx3[maxn],nx4[maxn];
struct TopTree{
    struct Node{
        Info val;
        int ls,rs,fa;
        int siz;
        bool ty;
        Info *sum;
        int *a;
        vector<Info>ans;
    }t[maxn];
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define fa(p) t[p].fa
#define val(p) t[p].val
#define siz(p) t[p].siz
#define ty(p) t[p].ty
#define a(p) t[p].a
#define ans(p) t[p].ans
#define sum(p,l,r) t[p].sum[l*siz(p)+r]
    int idx,rt;
    inline int NewNode(bool ty,int val=-INF){
        t[++idx]={{val},0,0,0,1,ty};
        return idx;
    }
    inline void PushUp(int p){
        siz(p)=siz(ls(p))+siz(rs(p));
        if(ty(p)) Rake(val(ls(p)),val(rs(p)),val(p));
        else Compress(val(ls(p)),val(rs(p)),val(p));
    }
    inline int Merge(int u,int v,bool ty){
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
    void Dfs2(int u){
        a(u)=mem+used,used+=siz(u);
        t[u].sum=(Info*)(mem+used),used+=8*siz(u)*siz(u);
        if(u<=n){
            a(u)[0]=u,sum(u,0,0)=val(u);
        }else{
            Dfs2(ls(u)),Dfs2(rs(u));
            int l=0,r=0,now=0;
            while(l<siz(ls(u))&&r<siz(rs(u))){
                if(a(ls(u))[l]<a(rs(u))[r])
                    a(u)[now++]=a(ls(u))[l++];
                else a(u)[now++]=a(rs(u))[r++];
            }
            while(l<siz(ls(u)))
                a(u)[now++]=a(ls(u))[l++];
            while(r<siz(rs(u)))
                a(u)[now++]=a(rs(u))[r++];
            for(int i=0,j=0;i<siz(u);++i){
                while(j<siz(ls(u))&&a(ls(u))[j]<a(u)[i])
                    ++j;
                if(j==siz(ls(u))) nx1[i]=-1;
                else nx1[i]=j;
            }
            for(int i=0,j=0;i<siz(u);++i){
                while(j<siz(rs(u))&&a(rs(u))[j]<a(u)[i])
                    ++j;
                if(j==siz(rs(u))) nx3[i]=-1;
                else nx3[i]=j;
            }
            for(int i=0,j=0;i<siz(u);++i){
                while(j+1<siz(ls(u))&&a(ls(u))[j+1]<=a(u)[i])
                    ++j;
                if(a(ls(u))[j]>a(u)[i]) nx2[i]=-1;
                else nx2[i]=j;
            }
            for(int i=0,j=0;i<siz(u);++i){
                while(j+1<siz(rs(u))&&a(rs(u))[j+1]<=a(u)[i])
                    ++j;
                if(a(rs(u))[j]>a(u)[i]) nx4[i]=-1;
                else nx4[i]=j;
            }
            for(int i=0;i<siz(u);++i)for(int j=i;j<siz(u);++j){
                Info L,R;
                if(~nx1[i]&&~nx2[j]&&nx1[i]<=nx2[j])
                    L=sum(ls(u),nx1[i],nx2[j]);
                if(~nx3[i]&&~nx4[j]&&nx3[i]<=nx4[j])
                    R=sum(rs(u),nx3[i],nx4[j]);
                if(ty(u)) Rake(L,R,sum(u,i,j));
                else Compress(L,R,sum(u,i,j));
            }
        }
    }
    void Dfs(int u){
        if(siz(u)<=B){
            used=0,Dfs2(u);
            ans(u).resize(m+1);
            for(int i=1,j=0;i<=m;++i){
                while(j<siz(u)&&a(u)[j]<ql[i].first)
                    ++j;
                if(j==siz(u)) nx1[ql[i].second]=-1;
                else nx1[ql[i].second]=j;
            }
            for(int i=1,j=0;i<=m;++i){
                while(j+1<siz(u)&&a(u)[j+1]<=qr[i].first)
                    ++j;
                if(a(u)[j]>qr[i].first) nx2[qr[i].second]=-1;
                else nx2[qr[i].second]=j;
            }
            for(int i=1;i<=m;++i){
                if(~nx1[i]&&~nx2[i]&&nx1[i]<=nx2[i])
                    ans(u)[i]=sum(u,nx1[i],nx2[i]);
                else ans(u)[i]={};
            }
        }else{
            Dfs(ls(u)),Dfs(rs(u));
            ans(u).resize(m+1);
            for(int i=1;i<=m;++i){
                if(ty(u)) Rake(ans(ls(u))[i],ans(rs(u))[i],ans(u)[i]);
                else Compress(ans(ls(u))[i],ans(rs(u))[i],ans(u)[i]);
            }
            ans(ls(u)).clear(),ans(ls(u)).shrink_to_fit();
            ans(rs(u)).clear(),ans(rs(u)).shrink_to_fit();
        }
    }
    void Solve(){
        Dfs(rt);
        for(int i=1;i<=m;++i)
            print(max(ans(rt)[i].m00,ans(rt)[i].m10));
    }
    inline void Init(){
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
    t.Solve();
    flush();
}
void init(){
    read(n);
    for(int i=1;i<=n;++i)
        read(a[i]);
    int u,v;
    for(int i=1;i<n;++i)
        read(u),read(v),e[u].push_back(v),e[v].push_back(u);
    e[n+1].push_back(1),e[1].push_back(n+1);
    Dfs(n+1,0); 
    t.Init();
    read(m);
    for(int i=1;i<=m;++i) 
        read(u),read(v),ql[i]={u,i},qr[i]={v,i},q[i]={u,v};
    sort(ql+1,ql+1+m);
    sort(qr+1,qr+1+m);
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