#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e8-3;
int n,m;
struct node{
    int val,pos;
    bool operator<(const node &x){
        return val<x.val;
    }
}a[maxn],b[maxn];
int c[maxn],d[maxn];
ll ans;
// void fen(int L,int R){
//     if(L==R) return;
//     int mid=L+R>>1;
//     fen(L,mid);
//     fen(mid+1,R);
//     int idl=L-1,idr=mid,i=L;
//     for(;i<=R;++i){
//         if(c[idl+1]>c[idr+1]) d[i]=c[++idl];
//         else d[i]=c[++idr],ans=(ans+idl-L+1)%mod;
//         if(idl==mid||idr==R) break; 
//     }
//     while(idl<mid) d[++i]=c[++idl];
//     while(idr<R) d[++i]=c[++idr],ans=(ans+idl-L+1)%mod;
//     for(i=L;i<=R;++i) c[i]=d[i];
// }
void fen(int L, int R) {
    if (L == R) return;
    int mid = (L + R) >> 1;
    fen(L, mid);
    fen(mid + 1, R);
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R) {
        if (c[i] <= c[j])  d[k++] = c[i++];
        else  d[k++] = c[j++], ans = (ans + mid - i + 1) % mod;
    }
    while (i <= mid) d[k++] = c[i++];
    while (j <= R) d[k++] = c[j++];
    for (i = L; i <= R; i++) c[i] = d[i];
}

void solve(){
    
    // for(int i=1;i<=n;++i) cout<<c[i]<<" ";
    // cout<<endl;
    fen(1,n);
    // for(int i=1;i<=n;++i) cout<<c[i]<<" ";
    // cout<<endl;
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].val,a[i].pos=i;
    for(int i=1;i<=n;++i) cin>>b[i].val,b[i].pos=i;
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;++i)
        c[b[i].pos]=a[i].pos;
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