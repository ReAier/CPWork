#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m,K;
struct Edge{
    int u,v,w;
    inline bool operator<(const Edge &x)const{
        return w<x.w;
    }
};
Edge s[maxn*200];
int a[20],c[20][maxn];

int fa[maxn];
inline int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline bool merge(int u,int v){
    if(find(u)==find(v)) return 0;
    fa[find(u)]=find(v);
    return 1;
}

bool use[20];
inline ll Chack(int st){
    for(int i=1;i<=n+K;++i) fa[i]=i;
    memset(use,0,sizeof(use));
    ll res=0,num=0,cnt=0;
    for(int i=1;i<=K;++i) if((st>>(i-1))&1) {
        res+=a[i];
        num++;
        use[i]=1;
    }
    for(int i=1;i<=m;++i){
        auto [u,v,w]=s[i];
        if(u>n&&!use[u-n]) 
            continue;
        if(merge(u,v)) {
            res+=w;
            if((++cnt)==(n+num-1)) 
                break;
        }else if(!st)  s[i].w=INF;
    }
    if(!st){
        sort(s+1,s+1+m);
        m=n-1;
    }
    return res;
}

void solve(){
    sort(s+1,s+1+m);
    ll ans=Chack(0);
    for(int i=1;i<=K;++i) for(int j=1;j<=n;++j) 
        s[++m]={i+n,j,c[i][j]};
    sort(s+1,s+1+m);
    for(int i=1;i<(1<<K);++i)
        ans=min(ans,Chack(i));
    cout<<ans;
}

void init(){
    cin>>n>>m>>K;
    int u,v,w;
    for(int i=1;i<=m;++i)
        cin>>u>>v>>w,s[i]={u,v,w};
    for(int i=1;i<=K;++i){
        cin>>a[i];
        for(int j=1;j<=n;++j)
            cin>>c[i][j];
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
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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