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
const int maxn=3e2+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m;

struct Matrix{
    ll a[maxn][maxn];
    ll R,C;
    Matrix(int R=n,int C=n,int x=0):R(R),C(C){
        memset(a,0,sizeof(a));
        for(int i=1;i<=R;++i) a[i][i]=x;
    }
    ll* operator[](const ll &x){
        return a[x];
    }
    Matrix operator*(Matrix x){
        Matrix res(R,x.C);
        for(int i=1;i<=R;++i) for(int j=1;j<=x.C;++j) for(int k=1;k<=C;++k)
            res[i][j]=((res[i][j]+a[i][k]*x[k][j])%mod+mod)%mod;
        return res;
    }
    Matrix operator+(Matrix &x){
        Matrix res(R,C);
        for(int i=1;i<=R;++i) for(int j=1;j<=C;++j) res[i][j]=a[i][j]+x[i][j];
        return res;
    }
    Matrix Pow(ll t){
        Matrix A=*this,res(R,C,1);
        while(t){
            if(t&1) res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
}A,B;


void solve(){
    B=A.Pow(m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            cout<<B[i][j]<<" ";
        cout<<'\n';
    }
}
void init(){
    cin>>n>>m;
    A=Matrix(n,n);
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
        cin>>A[i][j];
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