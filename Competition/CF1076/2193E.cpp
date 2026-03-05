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
ll a[maxn];
bitset<maxn>b;

void solve(){
    ll j=1;
    for(ll i=1;i<=n;++i){
        if(b[i]){
            cout<<"1 ";
            continue;
        }else if(i==1){
            cout<<"-1 ";
            continue;
        }
        while(a[j]*a[j]<=i&&j<=m)
            ++j;
        ll res=0,now=i;
        for(int k=j-1;k>=1;--k){
            while((now!=1)&&((now%a[k])==0)) 
                now/=a[k],++res;
        }
        if(now==1) cout<<res<<' ';
        else if(b[now]) cout<<res+1<<' ';
        else cout<<"-1 ";
    }cout<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        b[i]=0;
    for(int i=1;i<=n;++i)
        cin>>a[i],b[a[i]]=1;
    for(int i=1;i<=n;++i) if(a[i]==1)
        a[i]=INF;
    sort(a+1,a+1+n);
    m=unique(a+1,a+1+n)-a-1;
    while(a[m]==INF) m--;
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