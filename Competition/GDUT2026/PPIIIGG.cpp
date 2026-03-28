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
const int maxn=1e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
string s;
ll suf[maxn],P[maxn],I[maxn<<1];
ll C[maxn][maxn],sum[maxn][maxn];

void solve(){
    ll ans=0,of=n+3;
    P[0]=1;
    for(int i=1;i<=n;++i){
        if(s[i-1]=='P'){
            for(int j=n;j>=1;--j)
                P[j]=(P[j-1]+P[j])%mod;
        }else if(s[i-1]=='I'){
            for(int j=n;j>=-n;--j)
                I[j+of]=(I[j-1+of]+I[j+of])%mod;
            for(int j=1;j<=n;++j)
                I[2-j+of]=(I[2-j+of]+P[j])%mod;
        }else{
            for(ll j=1;j<=n;++j)
                ans=(ans+(sum[suf[i+1]][min(j-1,suf[i+1])]*I[j+of]%mod))%mod;
        }
    }
    cout<<ans%mod<<'\n';
}
void init(){
    cin>>n>>s;
    memset(P,0,sizeof(P));
    memset(I,0,sizeof(I));
    suf[n+1]=0;
    for(int i=n;i>=1;--i)
        suf[i]=suf[i+1]+(s[i-1]=='G');
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
    cin>>T;
    C[0][0]=sum[0][0]=1;
    for(int i=1;i<=maxn-1;++i){
        C[i][i]=C[i][0]=sum[i][0]=1;
        for(int j=1;j<=maxn-1;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        for(int j=1;j<=maxn-1;++j)  
            sum[i][j]=(sum[i][j-1]+C[i][j])%mod;
    }
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