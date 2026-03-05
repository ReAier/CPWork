#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=200+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m,q;

struct Matrix{
    ll a[maxn][maxn];
    ll R,C;
    Matrix(int R=n,int C=n,ll x=0):R(R),C(C){
        memset(a,0,sizeof(a));
        for(int i=1;i<=R;++i) a[i][i]=x;
    }
    ll* operator[](const int &x){
        return a[x];
    }
    Matrix operator*(Matrix x){
        Matrix res(R,x.C);
        for(int i=1;i<=R;++i) for(int j=1;j<=x.C;++j) for(int k=1;k<=C;++k)
            res[i][j]^=a[i][k]*x[k][j];
        return res;
    }
}A,Pow[40];


void solve(){
    ll t;
    while(q--){
        cin>>t;
        Matrix ans=A;
        for(int i=0;i<32;++i)if((t>>i)&1) ans=ans*Pow[i];
        cout<<ans[1][1]<<endl;
    }
}

void init(){
    cin>>n>>m>>q;
    A=Matrix(1,n);
    for(int i=1;i<=n;++i)
        cin>>A[1][i];
    ll u,v;
    Pow[0]=Matrix(n,n);
    for(int i=1;i<=m;++i)
        cin>>u>>v,Pow[0][u][v]=Pow[0][v][u]=1;
    
    for(int i=1;i<32;++i)
        Pow[i]=Pow[i-1]*Pow[i-1];
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