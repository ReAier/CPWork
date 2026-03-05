#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5000+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
vector<int>v;
bool vis[maxn][maxn];

void solve(){
    ll ans=0;
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j){
        int flg=0,l=i,r=j;
        while(l<=r){
            if(vis[l][r]) break;
            if(v[l]<v[r])
                break;
            if(v[r]<v[l]) {
                flg=1;
                break;
            }
            l++,r--;
        }
        if(!flg) vis[i][j]=1;
        ans+=flg;
    }
    cout<<ans;
}

void init(){
    char ch=getchar();
    while(isdigit(ch))
        v.push_back(ch-'0'),ch=getchar();
    n=v.size();
    for(int i=0;i<n;++i)
        vis[i][i]=1;
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