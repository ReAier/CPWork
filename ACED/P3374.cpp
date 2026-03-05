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
    int x,y,k;
    for(int i=1;i<=n;++i) scanf("%d",&k),add(i,k);
    while (m--){
        scanf("%d%d%d",&x,&y,&k);
        if(x==1)
            add(y,k);

        else 
            printf("%d\n",query(k)-query(y-1));
    }
    AC
}