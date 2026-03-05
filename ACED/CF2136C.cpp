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
int n,m;
int a[maxn],suf[maxn];
vector<int> pos[maxn];

struct BIT{
    int mx[maxn];
    void Change(int x,int k){
        while(x<=n) 
            mx[x]=max(mx[x],k),x+=lowbit(x);
    }
    int Query(int x){
        int ans=0;
        while(x)
            ans=max(ans,mx[x]),x-=lowbit(x);
        return ans;
    }
    void Init(){
        for(int i=1;i<=n;++i)
            mx[i]=0;
    }
}t;

void solve(){
    for(int v=1;v<=n;++v){
        for(int i=0;i+v-1<pos[v].size();++i)
            suf[pos[v][i]]=pos[v][i+v-1];
    }
    for(int i=1;i<=n;++i)
        t.Change(suf[i],t.Query(i-1)+a[i]);
    cout<<t.Query(n)<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        pos[i].clear(),suf[i]=INF;
    t.Init();
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pos[a[i]].push_back(i);
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