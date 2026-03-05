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
int fa[maxn],d[maxn];
vector<int>leaf,tmp;
void solve(){
    int ans=INF,num=0;
    while(leaf.size()){
        ans=min(ans,(int)(leaf.size()+num));
        ++num;
        for(int v:leaf) if(!(--d[fa[v]])) 
            tmp.push_back(fa[v]);
        leaf.clear();
        swap(leaf,tmp);
    }
    cout<<ans<<'\n';
}

void init(){
    cin>>n;
    leaf.clear(),tmp.clear();
    for(int i=1;i<=n;++i)
        d[i]=0;
    int p;
    for(int i=2;i<=n;++i)
        cin>>p,fa[i]=p,d[p]++;
    for(int i=1;i<=n;++i)
        if(!d[i]) leaf.push_back(i);
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