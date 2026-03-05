#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;

struct BitTree2{
    unordered_map<int,int>t[maxn];
#define lowbit(x) (x&(-x))
    void Add(int x,int y,int k){
        while(x<=n){
            for(int i=y;i<=n;i+=lowbit(i)) 
                t[x][i]+=k;
            x+=lowbit(x);
        }
    }
    int Query(int x,int y){
        int ans=0;
        while(x){
            for(int i=y;i;i-=lowbit(i)) 
                ans+=t[x][i];
            x-=lowbit(x);
        }
        return ans;
    }
}t;

void solve(){
    int opt,l,r;
    while(m--){
        cin>>opt>>l>>r;
        if(opt==1) t.Add(l,r,1);
        else cout<<t.Query(l,n)-t.Query(l,r-1)<<'\n';
    }
}

void init(){
    cin>>n>>m;
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