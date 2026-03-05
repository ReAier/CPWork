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
int n,m,h,l;
int a[maxn];

void solve(){
    int m1=0,m2=0;
    for(int i=1;i<=n;++i){
        if(a[i]<=h) ++m1;
        if(a[i]<=l) ++m2;
    }
    if(m1<m2) swap(m1,m2);
    m1-=m2;
    cout<<min(m1,m2)+max(0,(m2-m1)/2)<<'\n';
}
void init(){
    cin>>n>>h>>l;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    
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