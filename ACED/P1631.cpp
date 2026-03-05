#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
int a[maxn],b[maxn],idx[maxn],ans[maxn];
struct node{
    int id,val;
    node(){}
    node(int ID,int VAL):id(ID),val(VAL){}
    bool operator<(const node &x) const{
        return val>x.val;
    }
};

priority_queue<node>q;

void solve(){
    for(int i=1;i<=n;++i) q.push(node(i,a[i]+b[1]));
    for(int i=1;i<=n;++i){
        node u=q.top();
        q.pop();
        ans[i]=u.val;
        q.push(node(u.id,a[u.id]+b[++idx[u.id]]));
    }
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i) idx[i]=1;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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