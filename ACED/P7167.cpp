#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+10,INF=1e9+10,mod=1e9+7;
int n,m;
int d[maxn],v[maxn],nx[maxn][25],sum[maxn][25];


void solve(){
    int r,c;
    while(m--){
        cin>>r>>c;
        c-=v[r];
        if(c>0) for(int i=20;i>=0;--i) if(sum[r][i]<=c) c-=sum[r][i],r=nx[r][i];
        cout<<(c>0?nx[r][0]:r)<<endl;
    }
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>d[i]>>v[i];
    d[0]=INF,v[0]=INF;
    stack<int>s;
    s.push(0);
    for(int i=n;i>=1;--i){
        while(d[s.top()]<=d[i]) s.pop();
        nx[i][0]=s.top();
        sum[i][0]=v[s.top()];
        s.push(i);
    }

    for(int i=1;i<=20;++i){
        for(int j=1;j<=n;++j){
            nx[j][i]=nx[nx[j][i-1]][i-1];
            sum[j][i]=sum[j][i-1]+sum[nx[j][i-1]][i-1];
            if(sum[j][i]>INF) sum[j][i]=INF;
        }
    }
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