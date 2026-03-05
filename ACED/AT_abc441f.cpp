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
const int maxn=5e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
ll c[1010],v[1010];
ll pre[1010][maxn],suf[1010][maxn];

void Dp(){
    for(int i=1;i<=n;++i) {
        for(int j=1;j<c[i];++j) 
            pre[i][j]=pre[i-1][j];
        for(int j=m;j>=c[i];--j) 
            pre[i][j]=max(pre[i-1][j],pre[i-1][j-c[i]]+v[i]);
    }
    for(int i=n;i>=1;--i) {
        for(int j=1;j<c[i];++j) 
            suf[i][j]=suf[i+1][j];
        for(int j=m;j>=c[i];--j) 
            suf[i][j]=max(suf[i+1][j],suf[i+1][j-c[i]]+v[i]);
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
        pre[i][j]=max(pre[i][j],pre[i][j-1]);
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
        suf[i][j]=max(suf[i][j],suf[i][j-1]);
}

void solve(){
    Dp();
    ll mx=0;
    for(int i=1;i<=m;++i)
        mx=max(mx,pre[n][i]);
    for(int i=1;i<=n;++i){
        bool A=0,C=0;
        for(int j=0;j<=m;++j){
            if(pre[i-1][j]+suf[i+1][m-j]==mx)
                C=1;
            if(m>=j+c[i]&&pre[i-1][j]+suf[i+1][m-j-c[i]]+v[i]==mx)
                A=1;
        }
        if(A&&C) 
            cout<<"B";
        else if(A) 
            cout<<"A";
        else cout<<"C";
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>c[i]>>v[i];
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