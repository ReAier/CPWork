#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn],sum,me,ans[maxn],idx;
bool hs[maxn];
void Add(int x){
    sum^=x;
    if(x<=n) hs[x]=1;
    while(hs[me]) ++me;
}

void solve(){
    while(sum!=me){
        int k=sum^me;
        ans[++idx]=k;
        Add(k);
    }
    cout<<idx<<'\n';
    for(int i=1;i<=idx;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
}
void init(){
    cin>>n;
    sum=me=idx=0;
    memset(hs,0,sizeof(hs));
    for(int i=1;i<=n;++i){
        cin>>a[i];
        Add(a[i]);
    }
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