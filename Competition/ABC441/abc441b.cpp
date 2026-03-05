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
bool a[1000],b[1000];
string sa,sb;

void solve(){
    string s;
    while(m--){
        cin>>s;
        bool noa=0,nob=0;
        for(char ch:s){
            if(!a[ch]) noa=1;
            if(!b[ch]) nob=1;
        }
        // cout<<noa<<" "<<nob<<endl;
        if(((!noa)&&(!nob))||(noa&&nob))
            cout<<"Unknown\n";
        else if(noa) cout<<"Aoki\n";
        else cout<<"Takahashi\n";
    }
}
void init(){
    cin>>n>>m>>sa>>sb;
    for(char ch:sa)
        a[ch]=1;
    for(char ch:sb)
        b[ch]=1;
    cin>>m;
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