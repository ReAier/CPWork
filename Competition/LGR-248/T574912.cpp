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
int a0[maxn],a[maxn],idx;

int Find(){
    int b,c,ans=0;
    for(b=1;b<=idx;b=c){
        for(c=2*b;c<=idx;++c){
            if(a[c]==a[c-b]){
                ++ans;
                break;
            }
        }
    }
}

void solve(){
    int l,r;
    while(m--){
        cin>>l>>r;
        idx=0;
        for(int i=l;i<=r;++i)
            a[++idx]=a0[i];
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) 
        cin>>a0[i];
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