#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
struct Node{
    int a,b;
    bool operator<(const Node &x)const{
        return x.b<b;
    }
}w[maxn];


bitset<maxn>vis;
void solve(){
    int maxai=1,maxa,mexb=0;
    for(int i=1;i<=n;++i) if(w[i].a>w[maxai].a) maxai=i;
    w[0]=w[maxai];
    maxa=w[maxai].a;
    for(int i=0;i<=n;++i){
        if(i==maxai) continue;
        vis[w[i].b]=1;
        while(vis[mexb])mexb++;
        printf("%d\n",maxa-mexb);
    }
}

void init(){
    cin>>n;
    vis.reset();
    for(int i=1;i<=n;++i) cin>>w[i].a;
    for(int i=1;i<=n;++i) cin>>w[i].b;
    sort(w+1,w+1+n);
    
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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