#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
#endif
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e4+10,INF=1e9+10,mod=1e9+7;
int n,m;

int fa[maxn];
int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}
void merge(int x,int y){
    fa[findfa(y)]=findfa(x);
}
struct qu{
    int a,b;
    qu(){}
    qu(int A,int B){a=A,b=B;}
};
vector<qu>F;
vector<int>g[maxn];
int cnt;

void solve(){
    for(int i=1;i<=n;++i){
        for(auto j:g[i]){
            for(auto k:g[j]){
                if(k!=i) F.push_back(qu(i,k));
            }
        }
    }
    for(auto i:F){
        merge(i.a,i.b);
    }
    for(int i=1;i<=n;++i){
        if(findfa(i)==i) ++cnt;
    }
    cout<<cnt;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) fa[i]=i;
    char ef;
    int a,b;
    while(m--){
        cin>>ef>>a>>b;
        if(ef=='E'){
            g[a].push_back(b);
            g[b].push_back(a);
        }
        else{
            F.push_back(qu(a,b));
        }
    }
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T=1;
    // cin>>T;
    while(T--){
        init();
        solve();
    }
    AC
}