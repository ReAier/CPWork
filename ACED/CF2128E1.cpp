#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
int a[maxn],b[maxn];

int l,r;
bool Chack(int k){
    for(int i=1;i<=n;++i)
        b[i]=(a[i]>=k)?1:-1;
    int sum=0,lasmin=0,lasnow=0;
    for(int i=1;i<=n;++i){
        sum+=b[i];
        if(i>=m) {
            lasnow+=b[i-m];
            if(lasnow<=lasmin)
                l=i-m+1,lasmin=lasnow;
            if(sum-lasmin>=0)
                return r=i;
        }
    }
    return 0;
}

void solve(){
    int L=1,R=n;
    while(L<R-1){
        int mid=L+R>>1;
        if(Chack(mid)) L=mid;
        else R=mid-1;
    }
    if(!Chack(R)){
        Chack(L);
        cout<<L<<" "<<l<<" "<<r<<'\n';
    }else cout<<R<<" "<<l<<" "<<r<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
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