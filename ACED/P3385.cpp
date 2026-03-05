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
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        d[i]=Inf;
        e[i].clear();
        mcnt[i]=0;
        inq[i]=0;
    }
    while (Q.size())
        Q.pop();
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        if(w>=0) e[v].push_back({u,w});
    }
}
void solve(){
    if(SPFA(1))
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        init();
        solve();
    }
    AC
}