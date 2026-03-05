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

struct Edge{
    int u,v,w,nx;
    Edge(){}
    Edge(int U,int V,int W,int Nx):u(U),v(V),w(W),nx(Nx){}
    bool operator<(const Edge &x)const{return w<x.w;}
}e[maxn*4];

int head[maxn],midx=1;

void addedge(int u,int v,int w=1){
    if(u==v) return;
    e[++midx]=Edge(u,v,w,head[u]);
    head[u]=midx;
}

vector<int>br; //桥
// bool cut[maxn];//割点
// int s[maxn],top; //判断scc,edcc,vdcc
// vector<vector<int>> ans; //判断scc,edcc,vdcc
// bool ins[maxn]; //判断scc
int dfn[maxn],low[maxn],tim;

void dfs(int u,int in=0){ // in用于判断edcc,vdcc
    //if(!in&&!head[u]) return ans.push_back({u}),void();//特判vdcc
    dfn[u] = low[u] = ++tim;

    //s[++top]=u; //当需要得到edcc,vdcc,scc时
    //ins[u]=1; //当需要scc时
    int child=0;
    for (int i=head[u];i;i=e[i].nx) {
        int v=e[i].v;
        if (!dfn[v]) {
            dfs(v,i); //判断edcc,vdcc
            ++child;
            low[u] = min(low[u], low[v]);
            if(low[v]>dfn[u]) br.push_back(i); //桥

            // if(in&&low[v]>=dfn[u]) cut[u]=1; //割点

            // vdcc
            // if(low[v]>=dfn[u]){
            //     vector<int>vdcc;
            //     while(1){
            //         vdcc.push_back(s[top]);
            //         if(s[top--]==v) break;
            //     }
            //     vdcc.push_back(u);
            //     ans.push_back(vdcc);
            // }
        } else if(i!=(in^1)) //判断edcc,vdcc
            low[u] = min(low[u], dfn[v]);   
    }

    // if(child>=2&&(!in)) cut[u]=1; //割点判断

    //edcc和scc
    // if(dfn[u]==low[u]){    
    //     vector<int> secc;
    //     while(1){
    //         secc.push_back(s[top]);
    //         ins[s[top]]=0;   //scc
    //         if(s[top--]==u) break;
    //     }
    //     ans.push_back(secc);
    // }
}
vector<pair<int,int>>ans;
void solve(){
    dfs(1);
    for(int i:br) ans.push_back({e[i].u,e[i].v});
    sort(ans.begin(),ans.end());
    for(auto [u,v]:ans) cout<<u<<" "<<v<<endl;
}

void init(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;++i) cin>>u>>v,addedge(u,v),addedge(v,u);
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