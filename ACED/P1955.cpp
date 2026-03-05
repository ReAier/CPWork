#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define OPEN_FILE
#endif
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
int fa[maxn],idx;
map<int,int>mp;
int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}
void merge(int x,int y){
    fa[findfa(y)]=findfa(x);
}
struct qu{
    int a,b;
    bool e;
    qu(){}
    qu(int A,int B,bool E){a=A,b=B,e=E;}
};
deque<qu>q;

void solve(){
    for(auto i:q){
        if(i.e) 
            merge(i.a,i.b);
        else
            if(findfa(i.a)==findfa(i.b)) return printf("NO\n"),void();
    }
    printf("YES\n");
}
void init(){
    cin>>n;
    idx=0;
    mp.clear();
    q.clear();
    int a,b,e;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>e;
        if(!mp[a]) 
            mp[a]=++idx;
        if(!mp[b]) 
            mp[b]=++idx;
        a=mp[a];
        b=mp[b];
        if(e) q.push_front(qu(a,b,e));
        else q.push_back(qu(a,b,e));
    }
    for(int i=1;i<=idx;++i) fa[i]=i;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T=1;
    cin>>T;
    while(T--){
        init();
        solve();
    }
    AC
}