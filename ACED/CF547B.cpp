#include<bits/stdc++.h>
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include<ctime>
// #define OPEN_FILE
// #define OPEN_TIME
#endif

#define ll long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

const int maxn=1e6+10,INF=0x3f3f3f3f;
int mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct Node{
    int val,len;
    bool operator<(Node x){
        return val>x.val;
    }
}b[maxn];
int s[maxn],top;
int maxL[maxn],maxR[maxn];
int ans[maxn];
void solve(){
    for(int i=1;i<=n;++i)
        b[i].len=maxR[i]-maxL[i]+1,b[i].val=a[i];
    sort(b+1,b+1+n);
    int idx=1;
    for(int i=1;i<=n;++i){
        for(int j=idx;j<=b[i].len;++j)
            ans[j]=b[i].val;
        idx=max(idx,b[i].len+1);
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i){
        while(a[s[top]]>=a[i]) 
            --top;
        maxL[i]=s[top]+1;
        if(!top) maxL[i]=1;
        s[++top]=i;
    }
    top=0;
    for(int i=n;i>=1;--i){
        while(a[s[top]]>=a[i])
            --top;
        maxR[i]=s[top]-1;
        if(!top) maxR[i]=n;
        s[++top]=i;
    }
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
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