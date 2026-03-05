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

void solve(){
    if(n==1) return cout<<"1\n",void();
    int i,j;
    for(i=0;i<n;++i){
        if(s[i]=='*'){
            if(i>0&&(s[i-1]=='>'||s[i-1]=='*'))
                return cout<<"-1\n",void();
            if(i<n-1&&(s[i+1]=='<'||s[i+1]=='*'))
                return cout<<"-1\n",void();
        }
    }
    for(i=0;i<n;++i) if(s[i]=='>') 
        break;
    for(;i<n;++i) if(s[i]=='<')
        return cout<<"-1\n",void();
    i=0,j=n-1;
    while(s[i]!='>'&&i<n) ++i;
    while(s[j]!='<'&&j>=0) --j;
    cout<<max(i,n-j-1)<<'\n';
}
void init(){
    cin>>s;
    n=s.size();
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