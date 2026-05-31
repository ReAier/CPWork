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

int f(int u) {
    if(e[u].size() == 0) 
        return 1;
    if(e[u].size() == 1)
        return f(e[u][0]);
    int mx=0,mx2=0;
    for(int v:e[u]) {
        int k = f(v);
        if(k>=mx)
            mx2=mx,mx=k;
        else if(k>=mx2) 
            mx2=k;
    }
    return max(mx,mx2+1);
}

void solve() {
    cout<<f(1)<<'\n';
}
void init() {
    cin>>n;
    for(int i=0;i<=n;++i)
        e[i].clear();
    int u;
    for(int i=1;i<=n;++i) 
        cin>>u,e[u].push_back(i);
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