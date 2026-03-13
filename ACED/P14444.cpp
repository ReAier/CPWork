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
pii a[maxn];

vector<int>ans;
void solve(){
    int flg=0;
    for(int i=n-1;i>=1;--i){
        if(gcd(a[i].first,a[n].first)!=a[i].first)
            ++flg;
    }
    while((a[m].first==a[n].first)&&m>=1)
        --m;
    if(flg<=1) for(int i=m+1;i<=n;++i)
        ans.push_back(a[i].second);
    if(m==n-1){
        flg=0;
        n--;
        for(int i=n-1;i>=1;--i){
            if(gcd(a[i].first,a[n].first)!=a[i].first)
                ++flg;
        }
        while((a[m].first==a[n].first)&&(m>=1))
            --m;
        if(!flg) for(int i=m+1;i<=n;++i)
            ans.push_back(a[i].second);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int u:ans)
        cout<<u<<" ";
    cout<<'\n';
}
void init(){
    cin>>n;m=n;
    ans.clear();
    for(int i=1;i<=n;++i)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
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