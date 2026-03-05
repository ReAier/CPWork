#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;

int f(int x){
    return x*n-x*(x+1)/2;
}

int Find(){
    int l=1,r=n;
    while(l<r){
        int mid=l+r>>1;
        if(f(mid)>=m) r=mid;
        else l=mid+1;
    }
    return l;
}

void solve(){
    if(m<=n){
        if(!m) cout<<n<<' '<<n<<" "<<'\n';
        else if(2*m<=n) cout<<n-1<<" "<<m+(n-2*m)<<'\n';
        else if(m<n) cout<<n-1<<" "<<n/2+(n%2)<<'\n';
        else cout<<n-2<<" "<<n/2<<'\n';
    }
    // else{
    //     int x=Find();
    //     cout<<n-x<<" "<<x<<'\n';
    // }
}

void init(){
    cin>>n>>m;
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