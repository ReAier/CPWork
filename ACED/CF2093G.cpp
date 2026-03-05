#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
int a[maxn];
struct Trie01{
    struct Node{
        int ch[2],val;
    }t[maxn];
#define ch(p) t[p].ch
#define val(p) t[p].val
    int idx=1;
    void Add(int x,int k){
        int p=1;
        for(int i=30;i>=0;--i){
            bool bi=(x>>i)&1;
            if(!ch(p)[bi]) ch(p)[bi]=++idx;
            p=ch(p)[bi],val(p)+=k;
        }
    }
    int Query(int x){
        int p=1,ans=0;
        for(int i=30;i>=0;--i){
            bool bi=(x>>i)&1;
            if(val(ch(p)[bi^1])>=1) 
                ans+=(1<<i),p=ch(p)[bi^1];
            else p=ch(p)[bi];
        }
        return ans;
    }
    void Init(){
        for(int i=1;i<=idx;++i)
            ch(i)[0]=ch(i)[1]=0,val(i)=0;
        idx=1;
    }
}t;

void solve(){
    int ans=INF;
    for(int i=1,j=1;i<=n;++i){
        while(j<=i&&t.Query(a[i])>=m){
            ans=min(ans,i-j+1);
            t.Add(a[j++],-1);
        }
        t.Add(a[i],1);
    }
    if(ans==INF) cout<<"-1\n";
    else cout<<ans<<'\n';
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    t.Init();
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