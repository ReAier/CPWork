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
ll a[maxn],sum,d[maxn],l=1,r,mx;
unordered_map<int,int>cnt;
void solve(){
    if(n&1) return cout<<mx<<'\n',void();

    for(ll i=1;i*i<=sum;++i)
        if(sum%i==0) 
            d[++r]=i,d[++r]=sum/i;
    sort(d+1,d+1+r);
    r=unique(d+1,d+1+r)-d-1;
    while(d[l]<mx) ++l;

    for(int i=l;i<=r;++i){
        int flg=1;
        for(auto[v1,c1]:cnt){
            int v2=d[i]-v1,c2=cnt[v2];
            if(v1==d[i]) continue;
            if(v1==v2) {
                if((c1&1)!=0) {
                    flg=0;
                    break;
                }
            }else{
                if(c1!=c2) {
                    flg=0;
                    break;
                }
            }
        }
        if(flg) cout<<d[i]<<" ";
    }
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],sum+=a[i],mx=max(mx,a[i]),cnt[a[i]]++;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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