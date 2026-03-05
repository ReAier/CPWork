#include<bits/stdc++.h>
#define AC return 0;
#define lowbit(x) (x & (-x))
using namespace std;
const int maxn = 1000005;
int sum[maxn],n,m;

void add(int x,int k){
    for(;x<=n;x+=lowbit(x)) sum[x]+=k;
}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)) res+=sum[x];
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    int x,y=0,k,opt;
    for(int i=1;i<=n;++i) scanf("%d",&x),add(i,x-y),y=x;
    while (m--){
        scanf("%d%d",&opt,&x);
        if(opt==1)
            scanf("%d%d",&y,&k),add(x,k),add(y+1,-k);
        else
            printf("%d\n",query(x));
    }
    AC
}