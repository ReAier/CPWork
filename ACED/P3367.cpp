#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int fa[maxn],n,m;

int find_fa(int x){
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}

void merge(int x,int y){
    fa[find_fa(x)]=find_fa(y);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) fa[i]=i;
    int z,x,y;
    while (m--){
        cin>>z>>x>>y;
        if(z==1) merge(x,y);
        else if(find_fa(x)==find_fa(y)) printf("Y\n");
        else printf("N\n");
    }
    

    return 0;
}