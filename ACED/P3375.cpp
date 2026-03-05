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
char a[maxn],b[maxn];
int nx[maxn];

void getnx(){
    int j=0;
    for(int i=2;i<=m;++i){
        while(j&&b[j+1]!=b[i]) j=nx[j];
        if(b[j+1]==b[i]) ++j;
        nx[i]=j;
    }
}
void kmp(){
    int j=0;
    for(int i=1;i<=n;++i){
        while (j&&b[j+1]!=a[i])j=nx[j];
        if(b[j+1]==a[i]) ++j;
        if(j==m) cout<<i-j+1<<endl,j=nx[j];
    }
}

void solve(){
    getnx();
    kmp();
    for(int i=1;i<=m;++i) cout<<nx[i]<<" ";
}

void init(){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1),m=strlen(b+1);
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