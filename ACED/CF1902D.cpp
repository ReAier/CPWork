#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
// #define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const int maxn=1e6+10,INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Vec{
    int x,y;
    bool operator<(const Vec a)const{
        return x==a.x?y<a.y:x<a.x;
    }
}a[maxn];
map<Vec,int>mpl,mpr,mp;
struct Query{
    Vec a;
    int id,l;
};

vector<Query>v[maxn];

bool ans[maxn];

void solve(){
    int x,y,l,r;
    for(int i=1;i<=m;++i){
        cin>>x>>y>>l>>r;
        if(mpl.count({x,y})&&mpl[{x,y}]<l) 
            ans[i]=1;
        else if(mpr[{x,y}]>=r)
            ans[i]=1;
        else v[r].push_back({{a[l-1].x+a[r].x-x,a[l-1].y+a[r].y-y},i,l});
    }
    for(int i=1;i<=n;++i){
        mp[a[i]]=i;
        for(auto [u,id,l]:v[i]) if(mp[u]>=l) 
            ans[id]=1;
    }
    for(int i=1;i<=m;++i) 
        if(ans[i]) cout<<"YES\n";
        else cout<<"NO\n";
}

void init(){
    cin>>n>>m;
    mpl[a[0]]=mpr[a[0]]=mp[a[0]]=0;
    getchar();
    for(int i=1;i<=n;++i){
        a[i]=a[i-1];
        switch(getchar()){
            case 'U':a[i].y++;
            break;
            case 'D':a[i].y--;
            break;
            case 'L':a[i].x--;
            break;
            case 'R':a[i].x++;
            break;
        }
        if(!mpl.count(a[i])) 
            mpl[a[i]]=i;
        mpr[a[i]]=i;
    }
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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