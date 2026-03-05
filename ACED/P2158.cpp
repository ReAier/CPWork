#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
bool np[maxn];
vector<int>p;
int eul[maxn];

void GetP(){
    eul[1]=1;
    for(int i=2;i<=n;++i){
        if(!np[i]) p.push_back(i),eul[i]=i-1;
        for(int j:p){
            np[i*j]=1;
            if(i*j>n) break;
            if(!(i%j)) {
                eul[i*j]=eul[i]*j;
                break;
            } else eul[i*j]=eul[i]*eul[j];
        }
    }
}


void solve(){
    GetP();
    ll ans=0;
    for(int i=1;i<n;++i) ans+=eul[i];
    cout<<(ans<<1|1)-(n==1);
}

void init(){
    cin>>n;
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