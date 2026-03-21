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
string s1,s2;

char mp[100];

void solve(){
    for(int i=1;i<=3;++i){
        bool flg=1;
        for(int j=0;j<n;++j) {
            if((s1[j]==mp[i])^(s2[j]==mp[i]))
                flg=0;
        }
        if(flg){
            cout<<"YES\n1\n";
            cout<<mp[i]<<'\n';
            return;
        }
    }
    cout<<"NO\n";
}
void init(){
    cin>>n>>s1>>s2;
    mp[1]='a',mp[2]='b',mp[3]='c';
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