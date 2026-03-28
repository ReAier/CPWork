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
ll n,m,L;
string s;
struct Node{
    ll x,y;
    Node operator+(const Node &k)const{
        return {x+k.x,y+k.y};
    }
    Node operator-(const Node &k)const{
        return {x-k.x,y-k.y};
    }
    bool operator<(const Node &k)const{
        return x==k.x?y<k.y:x<k.x;
    }
    ll operator*(const Node &k)const{
        return x*k.x+y*k.y;
    }
}b[maxn],U,V;
map<Node,int>mp;


void solve(){
    int ans=0;
    Node k;
    for(int i=1;i<=m;++i){
        cin>>k.x>>k.y;
        if(L){
            k={k*U,k*V};
            if(mp.count({(k.x%L+L)%L,k.y})&&mp[{(k.x%L+L)%L,k.y}]<=k.x) 
                ++ans;
        }else if(mp.count(k)) ++ans;
    }
    cout<<ans<<'\n';
}
void init(){
    cin>>n>>m>>s;
    mp.clear();
    for(int i=1;i<=n;++i){
        if(s[i-1]=='U')
            b[i]=b[i-1]+Node{0,1};
        if(s[i-1]=='D')
            b[i]=b[i-1]+Node{0,-1};
        if(s[i-1]=='L')
            b[i]=b[i-1]+Node{-1,0};
        if(s[i-1]=='R')
            b[i]=b[i-1]+Node{1,0};
    }
    U=b[n];
    V={-b[n].y,b[n].x};
    L=b[n]*b[n];
    for(int i=0;i<=n;++i){
        if(L){
            b[i]={b[i]*U,b[i]*V};
            if(!mp.count({(b[i].x%L+L)%L,b[i].y})||mp[{(b[i].x%L+L)%L,b[i].y}]>b[i].x) 
                mp[{(b[i].x%L+L)%L,b[i].y}]=b[i].x;
        }else mp[{b[i].x,b[i].y}]=b[i].x;
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