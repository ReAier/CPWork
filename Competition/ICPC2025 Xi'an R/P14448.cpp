#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
char s[maxn];
int d[3];
int l,r;

int Chack(int x){
    int nd[3];
    nd['P']=d['P'],nd['C']-d['C'],nd['W']=d['W'];

}

void solve(){
    for(int i=1;i<=n;++i) d[s[i]]++;
    int mad=max(d['P'],max(d['C'],d['W'])),sum=d['P']+d['C']+d['W'];
    if(mad>=sum-mad) return printf("Impossible\n"),void(); 

    l=0,r=0;
    for(int i=2;i<=n;++i) if(s[i]==s[i-1]) 
        r=i,l=l?l:i-1;
    if(!l) return printf("Beautiful\n"),void();

    d['P']=d['C']=d['W']=0;

    for(int i=l;i<=r;++i) 
        d[s[i]]++;
    mad=max(d['P'],max(d['C'],d['W'])),sum=d['P']+d['C']+d['W'];

    if(mad<sum-mad) {
        cout<<123<<endl;
    }else{

    }
    
}

void init(){
    scanf("%d%s",&n,s+1);
    d['P']=d['C']=d['W']=0;
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