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
const ll maxn=1e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;

ll mxy1,mxy2;
ll dis1,dis2,V=1e9;
void solve(){
    cout<<"? D "<<V<<endl;
    cin>>dis1;
    cout<<"? D "<<V<<endl;
    cin>>dis1;
    cout<<"? L "<<V<<endl;
    cin>>dis1;
    cout<<"? L "<<V<<endl;
    cin>>dis1;
    cout<<"? U "<<V<<endl;
    cin>>dis2;
    cout<<"? U "<<V<<endl;
    cin>>dis2;
    cout<<"? U "<<V<<endl;
    cin>>dis2;
    cout<<"? U "<<V<<endl;
    cin>>dis2;
    cout<<"! "<<(4*V+((mxy1+mxy2-dis1-dis2)/2))<<" "<<(mxy1-mxy2-dis1+dis2)/2<<endl;
}
void init(){
    cin>>n;
    mxy1=INF,mxy2=INF;
    ll x,y;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        mxy1=min(mxy1,x+y);
        mxy2=min(mxy2,x-y);
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