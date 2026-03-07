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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;

struct STtable{
    ll mia[maxn][25];
    ll GetMin(ll l,ll r){
        ll dif=r-l+1,ans=INF;
        if(l>r) return INF;
        for(ll i=20;i>=0;--i) if((dif>>i)&1)
            ans=min(mia[l][i],ans),l+=1<<i;
        return ans;
    }
    void Init(){
        for(ll k=1;k<=20;++k) for(ll i=1;i<=n;++i)
            mia[i][k]=min(mia[i+(1<<(k-1))][k-1],mia[i][k-1]);
    }
}st;
int b[10];
void solve(){
    int k;
    while(m--){
        cin>>k;
        for(int i=1;i<=k;++i)
            cin>>b[i];
        b[k+1]=n+1;
        ll ans=INF;
        for(int i=1;i<=k+1;++i)
            ans=min(ans,st.GetMin(b[i-1]+1,b[i]-1));
        cout<<ans<<'\n';
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>st.mia[i][0];
    st.Init();
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