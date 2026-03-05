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
string s;
int ch[30];

void solve(){
    bool flg1=1,flg2=1;
    for(int i=0;i<26;++i) if(!ch[i]) flg1=flg2=0;
    if(ch[s.front()-'a']<=1&&ch[s.back()-'a']<=1) flg2=0;
    if(!flg2){
        cout<<"No\n";
        if(!flg1) cout<<1<<" ";
        cout<<2<<'\n';
    } else cout<<"Yes\n";
}

void init(){
    cin>>s;
    memset(ch,0,sizeof(ch));
    for(char cc:s) ch[cc-'a']++;
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