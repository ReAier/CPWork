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
int n,m,B;
int a[maxn];
vector<int>pos[460];

void solve(){
    ll ans=0;
    for(int i=1;i<=n;++i) if(a[i]>B){
        for(int j=i-a[i],k=1;j>=1;j-=a[i],k++)
            ans+=(a[j]==k&&a[j]<=B);
        for(int j=i+a[i],k=1;j<=n;j+=a[i],k++)
            ans+=(a[j]==k&&a[j]<=B);
    }
    for(int i=1;i<=B;++i) if(pos[i].size()){
        for(int j=1;j<=B;++j){
            int d=i*j;
            for(int k:pos[i]) if(k+d<=n)
                ans+=a[k+d]==j;
        }
    }
    cout<<ans<<'\n';
}
void init(){
    cin>>n;
    B=sqrt(n);
    for(int i=1;i<=B;++i)
        pos[i].clear();
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]<=B)
            pos[a[i]].push_back(i);
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