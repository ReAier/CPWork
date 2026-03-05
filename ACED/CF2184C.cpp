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
int n,m;
map<int,int>mp;

void Chkmin(int u,int k){
    if(mp.count(u)&&~mp[u])
        mp[u]=min(mp[u],k);
    else mp[u]=k;
}

int ans=INF;
int Dfs(int u,int dep){
    if(u<m||dep>ans) return -1;
    if(u==m) {
        ans=min(ans,dep);
        return 0;
    }
    if(mp.count(u)) 
        return mp[u];
    int v1=u/2,v2=u-v1;
    v1=Dfs(v1,dep+1),v2=Dfs(v2,dep+1);
    Chkmin(u,v1+1),Chkmin(u,v2+1);
    return mp[u];
}

void solve(){
    Dfs(n,0);
    cout<<(ans==INF?-1:ans)<<'\n';
}
void init(){
    cin>>n>>m;
    mp.clear();
    ans=INF;
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