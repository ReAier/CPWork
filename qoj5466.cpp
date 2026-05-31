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
mt19937_64 mt(1145);
int n,m,k;
int a[maxn],b[maxn],l[maxn];
bool d[maxn];

void solve() {
    int j=1;
    for(int i=1;i<=m+1;++i,++j) {
        while(j<=n && a[j]!=b[i]) 
            d[j++]=1;
    }
    
}
void init() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) 
        cin>>a[i],d[i]=0;
    for(int i=1;i<=m;++i) 
        cin>>b[i];
    for(int i=1;i<=k;++i) 
        cin>>l[i];
}
int main() {
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
    // while(cin>>n) {
    while(T--) {
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}