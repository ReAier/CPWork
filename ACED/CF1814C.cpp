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
int n,m,s[3];
pii a[maxn];
int A[maxn],B[maxn],Asz,Bsz;
void solve(){
    for(int i=1;i<=n;++i){
        if((Asz+1)*s[1]<(Bsz+1)*s[2]) 
            A[++Asz]=a[i].second;
        else B[++Bsz]=a[i].second;
    }

    cout<<Asz<<' ';
    for(int i=1;i<=Asz;++i)
        cout<<A[i]<<" ";
    cout<<'\n'<<Bsz<<' ';
    for(int i=1;i<=Bsz;++i)
        cout<<B[i]<<" ";
    cout<<'\n';
}
void init(){
    cin>>n>>s[1]>>s[2];
    for(int i=1;i<=n;++i) 
        cin>>a[i].first,a[i].second=i;
    Asz=Bsz=0;
    sort(a+1,a+1+n,greater<pii>());
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