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
int a[maxn];
int las[maxn],lasp[maxn],nxtp[maxn],nxt[maxn];
struct BIT{
    ll a[maxn];
    void Add(int x,ll k){
        while(x<=n)
            a[x]+=k,x+=lowbit(x);
    }
    ll Query(int x){
        ll ans=0;
        while(x)
            ans+=a[x],x-=lowbit(x);
        return ans;
    }
}t;
ll dp[maxn];
void solve(){
    ll ans=0;
    for(int i=1;i<=n;++i){
        if(nxt[i]){
            dp[nxt[i]]+=t.Query(n)-t.Query(a[i])+t.Query(a[i]-1)+1;
        }
        t.Add(a[i],dp[i]);
    }
    for(int i=1;i<=n;++i)
        cout<<dp[i]<<' ';cout<<endl;
    for(int i=1;i<=n;++i)
        ans+=dp[i];
    cout<<ans;
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i){
        lasp[i]=las[a[i]];
        if(las[a[i]])
            nxtp[las[a[i]]]=i;
        las[a[i]]=i;
    }
    for(int i=1;i<=n;++i){
        if(!lasp[i]){
            int now=i;
            for(int j=1;j<a[i];++j)
                now=nxtp[now];
            nxt[i]=now;
        }else nxt[i]=nxtp[nxt[lasp[i]]];
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