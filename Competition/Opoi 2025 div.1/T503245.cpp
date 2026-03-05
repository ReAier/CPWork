#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn],cnt[maxn];
int Get(int l,int r,int k){
    memset(cnt,0,sizeof(cnt));
    for(int i=l;i<=r;++i) cnt[a[i]]++;
    for(int i=5e4;i>=1;--i) if(cnt[i]==k)   
        return i;
    return 0;
}

void solve(){
    int lastans=0,l,r,k;
    while(m--){
        cin>>l>>r>>k;
        l^=lastans,r^=lastans,k^=lastans;
        cout<<(lastans=Get(l,r,k))<<'\n';
    }
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
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