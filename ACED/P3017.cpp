#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m,a,b;
ll mp[1000][1000],sum[1000][1000];

ll getsum(int x1,int y1,int x2,int y2){
    return sum[x1][y1]-sum[x1][y2-1]-sum[x2-1][y1]+sum[x2-1][y2-1];
}

bool chack(int x){
    int now=0,num=0;
    for (int i=1;i<=n;i++){
        int dis=0,sum=0;
        for (int j=1;j<=m;j++)
            if (dis+getsum(i,j,now+1,j)<x)
                dis+=getsum(i,j,now+1,j);
            else{
                sum++;
                dis=0;
            }
        if (sum>=b){
            now=i;num++;
        }
    }
    if (num<a) return 0;
    return 1; 
}

void solve(){
    int l=1,r=1000000010;
    while(l+3<r){
        int mid=l+r>>1;
        if(chack(mid)) l=mid;
        else r=mid;
    }
    int ans=l;
    for(;ans<=r;++ans) if(!chack(ans)) break;
    cout<<ans-1;
}

void init(){
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>mp[i][j];
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mp[i][j];
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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