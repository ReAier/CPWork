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


void solve(){
    int ans1=0,x=0,y=0,ans2=0;
    for(int i=0;i<30;++i){
        if(i&1) x+=1<<i;
        else y+=1<<i;
        if(x>n||y>m){
            ans1=i;
            break;
        }
    }
    x=0,y=0;
    for(int i=0;i<30;++i){
        if(i&1) y+=1<<i;
        else x+=1<<i;
        if(x>n||y>m){
            ans2=i;
            break;
        }
    }
    cout<<max(ans1,ans2)<<'\n';
    // cout<<ans1<<" "<<ans2<<endl;
}
void init(){
    cin>>n>>m;
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