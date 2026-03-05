#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=200+10,INF=0x3f3f3f3f,mod=2009;
const double eps=1e-8;
int n,m;
struct Matrix{
    int a[maxn][maxn];
    int R,C;
    Matrix(int R=n,int C=n,int x=0):R(R),C(C){
        memset(a,0,sizeof(a));
        for(int i=1;i<=R;++i) a[i][i]=x;
    }
    int* operator[](const int &x){
        return a[x];
    }
    Matrix operator*(Matrix &x){
        Matrix res(R,x.C);
        for(int i=1;i<=R;++i) for(int j=1;j<=x.C;++j) for(int k=1;k<=C;++k)
            res[i][j]=(res[i][j]+a[i][k]*x[k][j])%mod;
        return res;
    }
    Matrix Pow(int t){
        Matrix A=*this,res(R,C,1);
        while(t){
            if(t&1) res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
}A;


void solve(){
    cout<<A.Pow(m)[1][n];
}

void init(){
    cin>>n>>m;
    A.R=A.C=n*9;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=8;++j)
            A[i+(j-1)*n][i+j*n]=1;
    for(int i=1;i<=n;++i) {
        int c;
        getchar();
        for(int j=1;j<=n;++j){
            c=getchar()-'0';
            if(!c) continue;
            A[i+(c-1)*n][j]=1;
        }
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