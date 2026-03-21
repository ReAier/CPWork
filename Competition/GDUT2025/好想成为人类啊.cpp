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
char s[maxn],t[maxn];

struct KMP{
    int nx[maxn];
    void getnx(char *b){
        int j=0;
        for(int i=2;i<=m;++i){
            while(j&&b[j+1]!=b[i]) j=nx[j];
            if(b[j+1]==b[i]) ++j;
            nx[i]=j;
        }
    }
    vector<int> kmp(char *a,char *b){
        int j=0;
        getnx(b);
        vector<int> ans;
        for(int i=1;i<=n;++i){
            while (j&&b[j+1]!=a[i])j=nx[j];
            if(b[j+1]==a[i]) ++j;
            if(j==m) ans.push_back(i-j+1),j=nx[j];
        }
        return ans;
    }
}kmp;
vector<int>res;

void solve(){
    if(!res.size())
        return cout<<"0\n",void();
    int ans=0,l=0,r=0;
    while(l<res.size()){
        while(r<res.size()&&res[r]-m<res[l])
            ++r;
        ++ans,l=r;
    }
    cout<<ans<<'\n';
}
void init(){
    cin>>n>>m;
    scanf("%s%s",s+1,t+1);
    res= kmp.kmp(s,t);
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