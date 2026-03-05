#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
vector<int>e[maxn];
int a[maxn];

int siz[maxn],son[maxn];
int cnt[maxn],frq[maxn],num;
bool ha[maxn];
ll ans;
void Dfs1(int u){
    siz[u]=1;
    for(int v:e[u]){
        Dfs1(v);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) 
            son[u]=v;
    }
}

void Add(int u){
    if(!ha[a[u]])
        ha[a[u]]=1,num++;
    frq[cnt[a[u]]]--;
    cnt[a[u]]++;
    frq[cnt[a[u]]]++;
}
void Del(int u){
    frq[cnt[a[u]]]--;
    cnt[a[u]]--;
    frq[cnt[a[u]]]++;
    if(!cnt[a[u]])
        ha[a[u]]=0,num--;
}

void Dfs2(int u){
    Add(u);
    for(int v:e[u]) Dfs2(v);
}
void Dfs3(int u){
    Del(u);
    for(int v:e[u]) Dfs3(v);
}

void Dfs(int u,bool kep){
    if(!u) return;
    for(int v:e[u]){
        if(v==son[u]) continue;
        Dfs(v,0);
    }
    Dfs(son[u],1);
    Add(u);
    for(int v:e[u]){
        if(v==son[u]) continue;
        Dfs2(v);
    }

    if(frq[siz[u]/num]==num)
        ans++;

    if(!kep)
        Dfs3(u);
}

void solve(){
    Dfs1(1);
    Dfs(1,1);
    cout<<ans;
}

void init(){
    cin>>n;
    int v,w;
    for(int u=1;u<=n;++u)
        cin>>w>>v,e[v].push_back(u),a[u]=w;
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