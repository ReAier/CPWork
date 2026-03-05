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
int n,m,r,q,k;


void solve(){
    if(q*n>=r-1){
        int kk=min(k,(r-1)%n)+((r-1)/n)*k;
        if(kk+1<=m) cout<<"Yes\n";
        else cout<<"No\n";
    }else{
        int kk=max(n-k,0)*q;
        if(r-kk<=m) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
void init(){
    cin>>r>>q>>n>>m;
    k=m/3;
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