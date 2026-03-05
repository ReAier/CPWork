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
const long double eps=1e-25,Pi=acos(-1);
int n,m;
struct Node{
    int id;
    long double x,y,the;
    vector<int>val;
    bool operator<(const Node &x)const{
        return the<x.the;
    }
}a[maxn];
int pos[maxn];
ll sum[maxn];

void solve(){
    int l,r;
    while(m--){
        cin>>r>>l;
        l=pos[l],r=pos[r];
        if(l<=r){
            cout<<sum[r]-sum[l-1]<<'\n';
        }else cout<<sum[n]-sum[l-1]+sum[r]<<'\n';
    };
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i].x>>a[i].y,a[i].id=i;
    for(int i=1;i<=n;++i)
        a[i].the=atan2(a[i].y,a[i].x);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;){
        int j=i;
        while(fabs(a[i].the-a[j].the)<eps&&j<=n)
            ++j;
        a[i].val.push_back(a[i].id);
        for(int k=i+1;k<j;++k){
            a[k].the=INF;
            a[i].val.push_back(a[k].id);
        }
        i=j;
    }
    sort(a+1,a+1+n);
    while(a[n].the>100) --n;
    for(int i=1;i<=n;++i){
        for(int id:a[i].val)
            pos[id]=i;
        sum[i]=sum[i-1]+a[i].val.size();
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