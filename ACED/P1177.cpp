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
int a[maxn],b[maxn];



void fen(int L,int R){
    if(L==R) return;
    int mid=L+R>>1;
    
    fen(L,mid);
    fen(mid+1,R);

    int idl=L-1,idr=mid,i;
    for(i=L;i<=R;++i){
        if(a[idl+1]<a[idr+1]) b[i]=a[++idl];
        else b[i]=a[++idr];
        if(idl==mid||idr==R) break;
    }
    while(idl<mid) b[++i]=a[++idl];
    while(idr<R) b[++i]=a[++idr];

    for(int i=L;i<=R;++i) a[i]=b[i]; 
}


void solve(){
    fen(1,n);
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
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