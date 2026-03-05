#include<bits/stdc++.h>
#define AC return 0;
using namespace std;
const int maxn = 1e6+10;
const int Inf=(1<<31)-1;
int n,m,s;
struct Edge{
    int v,w,next;
    Edge(){}
    Edge(int V,int W,int Next){
        v=V;w=W;next=Next;
    }
}e[maxn];
struct Node{
    int u,d;
    Node(int U,int D){
        u=U;d=D;
    }
    bool operator<(const Node &v)const{return d>v.d;}
};

int Hand[maxn],idx,d[maxn];
bool Vis[maxn];
priority_queue<Node>Q;
void AddEdge(int u,int v,int w){
    e[++idx]=Edge(v,w,Hand[u]);
    Hand[u]=idx;
}

void Dij(int s){
    for(int i=1;i<=n;++i)
        d[i]=Inf;
    d[s]=0;
    Q.push(Node(s,0));
    while (Q.size()){
        int u=Q.top().u;
        Q.pop();
        if(Vis[u])continue;
        Vis[u]=1;
        for(int i=Hand[u];i;i=e[i].next){
            if(d[e[i].v]>d[u]+e[i].w){
                d[e[i].v]=d[u]+e[i].w;
                Q.push(Node(e[i].v,d[e[i].v]));
            }
        }
    }
}


int main(){
    cin>>n>>m>>s;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        AddEdge(u,v,w);
    }
    Dij(s);
    for(int i=1;i<=n;++i)
        printf("%d ",d[i]);
    AC
}