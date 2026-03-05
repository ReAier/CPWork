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
int n,m,nm;
int a[maxn];

bool cnt[maxn];
int now;
stack<int>s;
void Clear(){
    while(s.size()){
        int u=s.top();s.pop();
        cnt[u]=0;
    }
    now=-1;
}
void Add(int x){
    if(!cnt[x]) s.push(x);
    cnt[x]=1;
    while(cnt[now+1])++now;
}
bool Chack(int x){
    Clear();
    now=-1;
    int k=0;
    for(int i=1;i<=n;++i){
        Add(a[i]);
        if(now>=x){
            Clear();
            ++k;
        }
    }
    return k>=m;
}
void solve(){
    int l=-1,r=nm;
    while(l<r-3){
        int mid=l+r>>1;
        if(Chack(mid)) l=mid;
        else r=mid;
    }
    int i=l;
    for(;i<=r;++i) if(!Chack(i)) break;
    cout<<i<<endl;
} 

void init(){
    cin>>n>>m;
    nm=0;
    for(int i=1;i<=n;++i)
        cin>>a[i],a[i]=min(a[i],n+2),nm=max(nm,a[i]);
    Clear();
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