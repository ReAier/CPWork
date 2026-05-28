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
mt19937_64 mt(1145);
int n,m;
vector<int>e[maxn];

bool vis[maxn],isr[maxn];
stack<int>s;
vector<int>a;
bool Dfs(int u,int fa) {
    s.push(u);
    vis[u]=1;
    for(int v:e[u]) if(v!=fa) {
        if(vis[v]) {
            while(s.top()!=v) 
                a.push_back(s.top()),isr[s.top()]=1,s.pop();
            a.push_back(v),isr[v]=1;
            return 1;
        }
        if(Dfs(v,u)) return 1;
    }
    s.pop();
    return 0;
}
const ull Mask=mt();
ull Hash(ull x) {
    x^=Mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<11;
    return x+1145;
}

ull res[maxn];
void Dfs2(int u,int fa) {
    res[u]=1;
    for(int v:e[u]) if(v!=fa && !isr[v]) 
        Dfs2(v,u),res[u]+=Hash(res[v]);
}

void solve() {
    if(m==n-1) return cout<<"YES\n",void();
    if(m>n) return cout<<"NO\n",void();
    Dfs(1,0);
    for(int u:a) Dfs2(u,0);
    if(a.size()&1){
        for(int i=1;i<a.size();++i) if(res[a[i]]!=res[a[0]]) 
            return cout<<"NO\n",void();
    }else {
        for(int i=2;i<a.size();i+=2) if(res[a[i]]!=res[a[0]]) 
            return cout<<"NO\n",void();
        for(int i=3;i<a.size();i+=2) if(res[a[i]]!=res[a[1]]) 
            return cout<<"NO\n",void();
    }
    cout<<"YES\n";
}
void init() {
    cin>>n>>m;
    while(s.size()) s.pop();
    for(int i=1;i<=n;++i)
        res[i]=vis[i]=isr[i]=0,e[i].clear(),a.clear();
    int u,v;
    for(int i=1;i<=m;++i)
        cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
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
    cin>>T;
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