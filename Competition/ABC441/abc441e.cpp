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
string s;
ll a[maxn];

struct BIT{
    int sum[maxn];
    void Add(int x,int k){
        x-=m;
        while(x<=n-m)
            sum[x]+=k,x+=lowbit(x);
    }
    int Query(int x){
        int ans=0;
        x-=m;
        while(x)
            ans+=sum[x],x-=lowbit(x);
        return ans;
    }
}t;

void solve(){
    ll sum=0,ans=0;
    t.Add(0,1);
    for(int i=0;i<n;++i){
        sum+=a[i];
        t.Add(sum,1);
        ans+=t.Query(sum-1);
    }
    cout<<ans;
}
void init(){
    cin>>n>>s;
    int su=0;
    for(int i=0;i<n;++i){
        if(s[i]=='A') 
            a[i]=1;
        if(s[i]=='B') 
            a[i]=-1;
        su+=a[i];
        m=min(m,su);
    }
    m-=10;
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