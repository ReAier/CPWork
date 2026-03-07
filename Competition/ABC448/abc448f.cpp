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
int n,m,B=81650;
//4472
struct Node{
    int x,y,id;
    bool operator<(const Node &k)const{
        if((x/B)!=(k.x/B))
            return x<k.x;
        return ((x/B)&1)?(y/B)<(k.y/B):(y/B)>(k.y/B);
    }
}a[maxn];

void solve(){
    sort(a+1,a+n+1);
    int pos1=1;
    for(int i=1;i<=n;++i) if(a[i].id==1)
        pos1=i;
    for(int i=pos1;i<=n;++i)
        cout<<a[i].id<<' ';
    for(int i=1;i<pos1;++i)
        cout<<a[i].id<<' ';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i].x>>a[i].y,a[i].id=i;
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