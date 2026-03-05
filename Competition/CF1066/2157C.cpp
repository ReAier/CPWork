#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1000+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m,k;
int me[maxn],mi[maxn];
struct Q{
    bool op;
    int l,r;
    bool operator<(Q x){
        return l<x.l;
    }
}q[maxn];
int ans[maxn];

void solve(){
    for(int i=1;i<=n;++i){
        // cout<<mi[i]<<" "<<me[i]<<endl;
        if(mi[i]&&!me[i]) ans[i]=k;
        else if(mi[i]&&me[i]) ans[i]=k+1;
    }
    sort(q+1,q+1+m);
    for(int i=1;i<=m;++i) if(q[i].op){
        int x=0;
        for(int j=q[i].l;j<=q[i].r;++j){
            if(!ans[j]) {
                ans[j]=x;
                x=(x+1)%k;
            }
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
}

void init(){
    cin>>n>>k>>m;
    int op,l,r;
    for(int i=1;i<=n;++i) ans[i]=0,me[i]=0,mi[i]=0;
    for(int i=1;i<=m;++i){
        cin>>op>>l>>r;
        q[i]={op==2,l,r};
        for(int i=l;i<=r;++i)
            me[i]+=(op==2),mi[i]+=(op==1);
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
    // ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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