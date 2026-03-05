#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m,VV,s;
struct Edge{
    int v,w,next;
}e[maxn];
int head[maxn],midx;
void addedge(int u,int v,int w){
    e[++midx]={v,w,head[u]};
    head[u]=midx;
}

struct node{
    int BagNum,BagCost,id;
    bool operator<(const node &x) const{
        return BagNum==x.BagNum?BagCost>x.BagCost:BagNum>x.BagNum;
    }
    node operator+(const int &x) const{
        node a;
        a.BagCost=BagCost+x;
        if(a.BagCost>VV) a.BagCost=x,a.BagNum=BagNum+1;
        else if(a.BagCost==VV) a.BagCost=0,a.BagNum=BagNum+1;
        else a.BagNum=BagNum;
        return a;
    }
}dis[maxn];
bool vis[maxn];
priority_queue<node>q;
void solve(){
    dis[s].BagCost=dis[s].BagNum=0;
    q.push(dis[s]);
    while(q.size()){
        int u=q.top().id;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next){
            // cout<<(dis[u]+e[i].w).BagNum<<" "<<(dis[u]+e[i].w).BagCost<<endl;
            // cout<<dis[e[i].v].BagNum<<" "<<dis[e[i].v].BagCost<<endl;
            // cout<<((dis[u]+e[i].w)<dis[e[i].v])<<endl;
            if(dis[e[i].v]<(dis[u]+e[i].w)) {
                dis[e[i].v]=dis[u]+e[i].w;
                dis[e[i].v].id=e[i].v;
                q.push(dis[e[i].v]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(dis[i].BagCost==INF) cout<<"-1 ";
        else if(dis[i].BagCost==0&&dis[i].BagNum==0) cout<<"1 ";
        else if(dis[i].BagCost>0) cout<<dis[i].BagNum+1<<" ";
        else cout<<dis[i].BagNum<<" ";
    }
}

void init(){
    cin>>n>>m>>VV>>s;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    for(int i=1;i<=n;++i) dis[i].BagCost=dis[i].BagNum=INF,dis[i].id=i;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
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