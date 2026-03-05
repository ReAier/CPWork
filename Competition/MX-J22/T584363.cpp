#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;



void solve(){
    string s;
    for(int i=1;i<=n;++i){
        cin>>s;
        int Bn=0,Sn=0;
        for(auto j:s){
            if(j<='Z'&&j>='A')
                Bn++;
        }
        int ans=abs(int(s.size())-5);
        if(s.size()>=5){
            ans=min(ans,abs(Bn-5));
        }
        cout<<ans<<endl;
    }
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