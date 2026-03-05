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
struct node{
    bool val;
    int l,r;
}a[maxn];

void solve(){
    int i=1,j=1;
    ll ans=0;
    while(j<=n){
        
    }
}

void init(){
    n=0;
    char ch=getchar();
    int idx=0;
    while(ch!='\n'){
        idx++;
        if((ch=='1')==a[n].val) a[n].r++;
        else a[++n].val=ch=='1',a[n].l=a[n].r=idx;
        ch=getchar();
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
    int T=1;
    cin>>T;
    getchar();
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