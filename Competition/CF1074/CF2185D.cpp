#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m,h;
ll a[maxn],a0[maxn];
bool ins[maxn];
stack<int>s;

void solve(){
    ll x,k;
    for(int i=1;i<=m;++i){
        cin>>x>>k;
        a[x]+=k;
        if(!ins[x])
            s.push(x),ins[x]=1;
        if(a[x]>h){
            while(!s.empty()){
                int u=s.top();s.pop();
                a[u]=a0[u];
                ins[u]=0;
            }
        }
    }
    for(int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    cout<<'\n';
}
void init(){
    cin>>n>>m>>h;
    for(int i=1;i<=n;++i)
        cin>>a0[i],a[i]=a0[i],ins[i]=0;
    while(s.size())s.pop();
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