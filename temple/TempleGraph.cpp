#include<bits/stdc++.h>

#define ForE(u) for(int i=head[u],v=e[i].v,w=e[i].w;i;i=e[i].nx,v=e[i].v,w=e[i].w)
#define ll long long
using namespace std;
const int maxn=1e4+10,INF=0x3f3f3f3f,mod=1e9+7;

int n,m;

struct Edge{
    ll u,v,w,nx;
    Edge(){}
    Edge(int U,int V,int W,int Nx):u(U),v(V),w(W),nx(Nx){}
    bool operator<(const Edge &x)const{return w<x.w;}
}e[maxn*4];

int head[maxn],midx=1;

void AddEdge(int u,int v,int w=1){
    if(u==v) return;
    e[++midx]=Edge(u,v,w,head[u]);
    head[u]=midx;
}

#pragma region SPFA

bool inq[maxn];
int mcnt[maxn],h[maxn];
bool Spfa(int s){
    queue<int>q;
    for(int i=0;i<=n;++i) h[i]=INF;
    q.push(s);
    h[s]=0;
    inq[s]=1;
    while (q.size()){
        int u =q.front();
        q.pop();
        inq[u]=0;
        ForE(u){
            if(h[v]>h[u]+w){
                h[v]=h[u]+w;
                mcnt[v]=mcnt[u]+1;
                if(mcnt[v]>n) return 0;
                if(!inq[v]) q.push(v),inq[v]=1;
            }
        }
    }
    return 1;
}

#pragma endregion

#pragma region Dijstra

int d[maxn];
bool vis[maxn];
void Dijstra(int s){
    priority_queue<pair<int,int>>q;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    q.push({0,s});
    d[s]=0;
    while(!q.empty()){
        auto u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ForE(u){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!vis[v]) q.push({-d[v],v});
            }
        }
    }
}

#pragma endregion

#pragma region Kruskal
int fa[maxn];
int Findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=Findfa(fa[x]);
}
void Merge(int x,int y){
    fa[Findfa(x)]=Findfa(y);
}
int Kruskal(){
    for(int i=1;i<=n;++i) fa[i]=i;
    sort(e+1,e+1+m);
    int tcnt=0,ans=0;
    for(int i=1;i<=m;++i){
        int u=e[i].u,v=e[i].v;
        if(Findfa(u)==Findfa(v)) continue;
        Merge(u,v);
        ans+=e[i].w;
        if(++tcnt==n-1) return ans;
    }
    return -1;
}
#pragma endregion

#pragma region Tarjan
// vector<int>br; //桥
// bool cut[maxn];//割点
// int s[maxn],top; //判断scc,edcc,vdcc
// vector<vector<int>> ans; //判断scc,edcc,vdcc
// bool ins[maxn]; //判断scc
int dfn[maxn],low[maxn],tim;

void Tarjan(int u,int in=0){ // in用于判断edcc,vdcc
    //if(!in&&!head[u]) return ans.push_back({u}),void();//特判vdcc
    dfn[u] = low[u] = ++tim;

    //s[++top]=u; //当需要得到edcc,vdcc,scc时
    //ins[u]=1; //当需要scc时
    int child=0;
    for (int i=head[u];i;i=e[i].nx) {
        int v=e[i].v;
        if (!dfn[v]) {
            Tarjan(v,i); //判断edcc,vdcc
            ++child;
            low[u] = min(low[u], low[v]);
            //if(low[v]>dfn[u]) br.push_back(i); //桥

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
        } else // if(ins[v]) //判断scc // if(i!=(in^1)) //判断edcc,vdcc,桥
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

#pragma endregion

#pragma region Dinic
int s,t,cur[maxn],dis[maxn];
ll Dfs(int u,ll las){
    if(u==t) return las;
    ll res=0;
    for(int i=cur[u];i&&las;i=e[i].nx){
        cur[u]=i;
        ll v=e[i].v,w=min(las,e[i].w);
        if(dis[v]==dis[u]+1&&w){
            ll k=Dfs(v,w);
            res+=k,las-=k;
            e[i].w-=k,e[i^1].w+=k;
        }
    }
    if(!res) dis[u]=INF;
    return res;
}
bool Bfs(int s,int t){
    queue<int>q;
    memcpy(cur,head,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nx){
            int v=e[i].v,w=e[i].w;
            if(dis[v]==INF&&w)
                dis[v]=dis[u]+1,q.push(v);
        }
    }
    return dis[t]!=INF;
}
ll Flow(int S,int T){
    ll ans=0;
    s=S,t=T;
    while(Bfs(s,t))
        ans+=Dfs(s,INF);
    return ans;
}
#pragma endregion

int main(){
    
    return 0;
}