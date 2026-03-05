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
stack<int>s;
int sum[maxn],suf[maxn];

void solve(){
    while(s.size())
        s.pop();
    for(int i=1;i<=n;++i){
        while(s.size()&&s.top()<a[i]) 
            s.pop();
        s.push(a[i]);
        sum[i]=s.size();
    }
    while(s.size())
        s.pop();
    for(int i=n;i>=1;--i){
        while(s.size()&&s.top()<a[i]) 
            s.pop();
        s.push(a[i]);
        suf[i]=s.size();
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,sum[i]+suf[i]);
    cout<<n-ans+1<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        sum[i]=suf[i]=0;
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