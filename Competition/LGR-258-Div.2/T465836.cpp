#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;

struct Node{
    int val,id;
}a[maxn];
int ans[maxn];
void solve(){
    for(int i=1;i<=n;++i){
        ans[a[i].id]=i;
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i].val,a[i].id=i;
    sort(a+1,a+1+n,[](Node x,Node y){return x.val<y.val;});
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