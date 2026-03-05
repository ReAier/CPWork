#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=300+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m,T,K;
ll c[maxn];
tuple<ll,ll,ll>f[maxn];

struct Matrix{
    ll a[maxn][maxn];
    ll R,C;
    Matrix(ll R=n,ll C=n):R(R),C(C){
        memset(a,-0x3f,sizeof(a));
    }
    ll* operator[](const ll &x){
        return a[x];
    }
    Matrix operator*(Matrix x){
        Matrix res(R,x.C);
        for(ll i=1;i<=R;++i) for(ll j=1;j<=x.C;++j) for(ll k=1;k<=C;++k)
            res[i][j]=max(res[i][j],a[i][k]+x[k][j]);
        return res;
    }
}E[40],A;

void solve(){
    for(ll i=1;i<=K;++i){
        auto [t,u,w]=f[i];
        t-=get<0>(f[i-1]);
        for(ll i=0;i<=31;++i) if((t>>i)&1)
            A=A*E[i];
        A[1][u]+=w;
    }

    for(ll i=0;i<=31;++i) if((T>>i)&1)
        A=A*E[i];

    if(A[1][1]<0) cout<<-1;
    else cout<<A[1][1];
}

void init(){
    cin>>n>>m>>T>>K;
    E[0]=Matrix(n*5,n*5);
    A=Matrix(1,n*5);
    for(ll i=1;i<=n;++i) 
        cin>>c[i];
    A[1][1]=c[1];
    
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=4;++j)
            E[0][i+(j-1)*n][i+j*n]=0;
    
    ll u,v,w;
    for(ll i=1;i<=m;++i){
        cin>>u>>v>>w;
        E[0][u+(w-1)*n][v]=c[v];
    }

    for(ll i=1;i<=31;++i) 
        E[i]=E[i-1]*E[i-1];

    ll t,x,y;
    for(ll i=1;i<=K;++i)
        cin>>t>>x>>y,f[i]={t,x,y};
    sort(f+1,f+1+K);
    T-=get<0>(f[K]);
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