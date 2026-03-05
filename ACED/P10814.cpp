#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Query{
    int x,id,val;
};
vector<Query>q[maxn];
int ans[maxn],a[maxn];
struct BitTree{
    int t[maxn];
#define lowbit(x) (x&(-x)) 
    void Add(int x,int k){
        while(x<=2e6){
            t[x]+=k;
            x+=lowbit(x);
        }
    }
    int Qeury(int x){
        int ans=0;
        while(x){
            ans+=t[x];
            x-=lowbit(x);
        }
        return ans;
    }
}t;

void solve(){
    for(int i=1;i<=n;++i){
        t.Add(a[i],1);
        for(auto [x,id,v]:q[i])
            ans[id]+=t.Qeury(x)*v;
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)   
        cin>>a[i];
    int l,r,x;
    for(int i=1;i<=m;++i){
        cin>>l>>r>>x;
        q[l-1].push_back({x,i,-1});
        q[r].push_back({x,i,1});
    }
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