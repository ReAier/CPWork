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

const int maxn=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;




struct Block{
    int Bnum,Blen;
    int a[maxn],b[maxn];
    int to[maxn],tn[maxn];
    void Make(int bi){
        for(int i=b[bi];i>b[bi-1];--i)
            if(i+a[i]<=b[bi])
                tn[i]=tn[i+a[i]]+1,to[i]=to[i+a[i]];
            else 
                tn[i]=1,to[i]=i;
    }
    void Change(int u,int k){
        a[u]=k;
        Make(min(Bnum,(u-1)/Blen+1));
    }
    int Query(int u){
        int ans=0;
        while(u<=n){
            ans+=tn[u];
            u=to[u];
            u+=a[u];
        }
        return ans;
    }
    void init(){
        Blen=pow(n,0.6);
        Bnum=n/Blen+(Blen*Blen<n);
        for(int i=1;i<=Bnum;++i)
            b[i]=i*Blen;
        b[Bnum]=n;//  ...
        for(int i=Bnum;i>=1;--i) 
            Make(i);
    }
}b;

void solve(){
    int opt,x,k;
    while(m--){
        cin>>opt>>x;
        ++x;
        if(opt==1)
            printf("%d\n",b.Query(x));
        else{
            cin>>k;
            b.Change(x,k);
        }
    }
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>b.a[i];
    cin>>m;
    b.init();
}

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime = clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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