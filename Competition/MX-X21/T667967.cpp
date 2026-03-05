#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e7+10,INF=1e9+10,mod=1e9+7;
int n,m;
int a[maxn],amax,b[maxn],idx;

int read(int &x){
    x=0;
    int f=1;
    char ch=getchar();
    while(!isdigit(ch)) {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)) {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}


void solve(){
    int i=amax==1?n:amax-1,j=amax==n?1:amax+1;
    while(a[amax]-a[i]<=m&&i!=amax) if(--i<1) i=n;
    while(a[amax]-a[j]<=m&&j!=amax) if(++j>n) j=1;
    if(i==amax&&j==amax) return printf("1\n"),void();
    while (i!=j){
        b[++idx]=a[j];
        if(++j>n) j=1; 
    }
    b[++idx]=a[i];
    int ans=2,lastmax=1,lastmin=1;
    for(i=1;i<=idx;++i){
        if(b[lastmax]-b[i]>m||b[i]-b[lastmin]>m) lastmax=lastmin=i,++ans;
        if(b[lastmax]<b[i]) lastmax=i;
        if(b[lastmin]>b[i]) lastmin=i;
    }
    printf("%d\n",ans);
}

void init(){
    read(n),read(m);
    amax=idx=0;
    for(int i=1;i<=n;++i) read(a[i]),amax=a[i]<a[amax]?amax:i;
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
    cin>>T;
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