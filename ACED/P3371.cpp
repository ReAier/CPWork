#include<bits/stdc++.h>
#define AC return 0;
using namespace std;
const int maxn = 1e5+10;
const int Inf=(1<<31)-1;
int n,m,d[maxn],mcnt[maxn];
struct Edge{
    int v,w;
};
vector<Edge>e[maxn];
queue<int>Q;
bool inq[maxn];
bool SPFA(int s){
    for(int i=1;i<=n;++i)
        d[i]=Inf;
    d[s]=0;
    Q.push(s);
    inq[s]=1;
    while (Q.size()){
        int u=Q.front();
        Q.pop();
        for(auto i:e[u]){
            if(d[u]+i.w<d[i.v]){
                d[i.v]=d[u]+i.w;
                mcnt[i.v]=mcnt[u]+1;
                if(mcnt[i.v]>n)return 0;
                Q.push(i.v);
                inq[i.v]=1;
            }
        }
    }
    return 1;
}

int main(){
    int s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});   
    }
    if(SPFA(s))
        for(int i=1;i<=n;++i)cout<<d[i]<<" ";
    AC
}