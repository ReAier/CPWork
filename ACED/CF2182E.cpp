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
ll n,m,k;
struct Fre{
    int x,y,z;
    bool operator<(const Fre &a)const{
        return z==a.z?x<a.x:z>a.z;
    }
}b[maxn];
int a[maxn];
bool vis[maxn];
multiset<int>s;
void solve(){
    int ans=0;
    for(int i=1;i<=n;++i){
        auto it=s.lower_bound(b[i].x);
        if(it!=s.end()) 
            ++ans,vis[i]=1,s.erase(it);
    }
    for(int i=n;i>=1;--i) if(!vis[i]){
        if(k>=b[i].z)
            k-=b[i].z,ans++;
        else break;
    }
    cout<<ans<<'\n';
}
void init(){
    cin>>n>>m>>k;
    s.clear();
    for(int i=1;i<=m;++i)
        cin>>a[i],s.insert(a[i]);
    for(int i=1;i<=n;++i){
        vis[i]=0;
        cin>>b[i].x>>b[i].y>>b[i].z;
        b[i].z-=b[i].y;
        k-=b[i].y;
    }
    sort(b+1,b+1+n);
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