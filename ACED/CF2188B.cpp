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
string s;
int a[maxn];
void solve(){
    ll len=0,ans=0;
    for(char ch:s){
        if(ch=='1'){
            if(len) a[++m]=len;
            len=0;
            ans++;
        }else ++len;
    }
    if(len) a[++m]=len;
    if(s[0]=='0'&&s[n-1]=='0'&&m==1)
        return cout<<(a[1]+2)/3<<'\n',void();
    if(s[0]=='0') a[1]++;
    if(s[n-1]=='0') a[m]++;
    for(int i=1;i<=m;++i)
        ans+=a[i]/3;
    cout<<ans<<'\n';
}
void init(){
    m=0;
    cin>>n>>s;
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