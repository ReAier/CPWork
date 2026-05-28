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
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
mt19937_64 mt(1145);
int n,m;
int a[maxn];
vector<pii>e[maxn];

struct Info{
    ll sum,rep,dif,cnt;
    Info operator+(const Info &x) const {
        if(cnt==0) return x;
        if(x.cnt==0) return *this;
        return {sum+x.sum,rep,gcd(dif,gcd(x.dif,abs(rep-x.rep))),cnt+x.cnt};
    }
    Info operator+(const ll &x) const {
        if(cnt==0) return *this;
        return {sum+x*cnt,rep+x,dif,cnt};
    }
    ll getAns() {
        if(cnt==0 || gcd(rep,dif)==0) return 0;
        return sum/gcd(rep,dif);
    }
}in[maxn];

ll d[maxn],ans=INF;
void Dfs1(int u,int fa) {
    if(d[u]) in[u]={0,0,0,1};
    for(auto[v,w]:e[u]) if(v!=fa) {
        Dfs1(v,u);
        in[u]=in[u]+(in[v]+w);
    }
}
void Dfs2(int u,int fa,Info out) {
    Info now = in[u] + out,suf = out + Info{0,0,0,d[u]};
    ans=min(ans,now.getAns());
    vector<Info>pre;
    pre.push_back({});
    for(auto[v,w]:e[u]) if(v!=fa) 
        pre.push_back(pre.back()+(in[v]+w));
    int idx = pre.size() - 1;
    for(int i = e[u].size() - 1; i >= 0; --i) {
        auto[v,w] = e[u][i];
        if(v==fa) continue;
        Dfs2(v, u, (pre[--idx] + suf) + w); 
        suf = suf + (in[v] + w);
    }
}

void solve() {
    if(m==1) return cout<<"0\n",void();
    Dfs1(1,0);
    Dfs2(1,0,{});
    cout<<ans*2<<'\n';
}
void init() {
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        cin>>a[i],d[a[i]]=1;
    int u,v,w;
    for(int i=1;i<n;++i)
        cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
}
int main() {
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
