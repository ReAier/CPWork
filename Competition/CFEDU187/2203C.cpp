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
ll n,m;
bitset<1000>a,b;

ll ans[100];
void solve(){
    ll las=0,mx=0;
    for(int i=1;i<64;++i){
        if(b[i]) las=i;
        if(a[i]){
            if(!las) return cout<<"-1\n",void();
            ans[las]+=(1ll<<(i-las));
        }

    }
    for(int i=1;i<64;++i)
        mx=max(mx,ans[i]);
    cout<<mx<<'\n';
}
void init(){
    cin>>n>>m;
    memset(ans,0,sizeof(ans));
    for(int i=0;i<63;++i){
        a[i+1]=(n>>i)&1;
        b[i+1]=(m>>i)&1;
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