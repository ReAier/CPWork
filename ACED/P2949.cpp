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
struct Node{
    int val,tim;
}a[maxn];


priority_queue<int>q;
void solve(){
    ll ans=0;
    for(int i=1;i<=n;++i){
        if(q.size()<a[i].tim) ans+=a[i].val,q.push(-a[i].val);
        else if(q.size()&&a[i].val>-q.top()) {
            ans+=a[i].val+q.top();
            q.push(-a[i].val);
            q.pop();
        }
    }
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i].tim>>a[i].val;
    sort(a+1,a+1+n,[](Node a,Node b){return a.tim==b.tim?a.val>b.val:a.tim<b.tim;});
    // for(int i=1;i<=n;++i) cout<<a[i].tim<<" "<<a[i].val<<endl;
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