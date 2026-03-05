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
bitset<maxn>a;
int ans[maxn];

void solve(){
    int maxl=0,now=0,sum=0;
    for(int i=1;i<=n;++i){
        if(!a[i]) {
            maxl=max(maxl,now);
            now=0;
        }else ++now,++sum;
    }maxl=max(maxl,now);
    if(maxl>=m) 
        return cout<<"NO\n",void();
    cout<<"YES\n";
    int l=1,r=sum+1;
    for(int i=1;i<=n;++i){
        if(a[i])
            cout<<l++<<" ";
        else cout<<r++<<' ';
    }cout<<'\n';
}
void init(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i)
        a[i]=(s[i-1]=='1');
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