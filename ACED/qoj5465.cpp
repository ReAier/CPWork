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
int n,m;
int a[maxn];

int f(int x) {
    return max(1,(x-1)/2);
}

void Pr(int x) {
    cout<<x<<'\n';
}

void solve() {
    int idx=1;
    while(idx<=n && gcd(a[1],a[idx])==a[1]) 
        ++idx;
    if(idx>n) return Pr(a[1]);
    if(f(a[idx])>=a[1]) return Pr(a[1]);
    Pr(a[1]/2);
}
void init() {
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
    n = unique(a+1,a+1+n) - a - 1;
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
    // cin>>T;
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