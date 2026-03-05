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
ll n,m,k;
int a[maxn];

void solve(){
    sort(a+1,a+m);
    int ans=0;
    while(k>=10){
        if(a[m]-1>a[n])
            k-=a[m]-1,a[m]=0;
        else k-=a[n--];
        ++ans;
    }
    cout<<ans<<'\n';
}
void init(){
    cin>>n;m=k=0;
    while(n) a[++m]=n%10,n/=10;
    for(int i=1;i<=m;++i)
        k+=a[i];
    n=m-1;
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