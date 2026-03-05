#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=100+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
unordered_map<int,int>mp;
int ans=INF;

void Dfs1(int i,int k,int cnt){
    if(i>((n>>1))||k>m) return;
    if(!mp.count(k)) mp[k]=cnt;
    else mp[k]=min(mp[k],cnt);
    Dfs1(i+1,k,cnt);
    Dfs1(i+1,k+(a[i+1]>>1),cnt+1);
    Dfs1(i+1,k+a[i+1],cnt);
}

void Dfs2(int i,int k,int cnt){
    if(i>n||k>m) return;
    if(cnt>ans) return;
    if(mp.count(m-k)) ans=min(ans,mp[m-k]+cnt);
    Dfs2(i+1,k,cnt);
    Dfs2(i+1,k+(a[i+1]>>1),cnt+1);
    Dfs2(i+1,k+a[i+1],cnt);
}

void solve(){
    Dfs1(0,0,0);
    Dfs2((n>>1),0,0);
    if(ans==INF) cout<<-1;
    else cout<<ans;
}

void init(){
    cin>>n>>m;
    m<<=1;
    for(int i=1;i<=n;++i)
        cin>>a[i],a[i]<<=1;
    sort(a+1,a+1+n);
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