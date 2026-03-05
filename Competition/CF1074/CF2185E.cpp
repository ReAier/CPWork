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
int n,m,k;
int a[maxn],b[maxn];
int l[maxn],r[maxn];
string s;
priority_queue<pii>ql,qr;
bool died[maxn];

void solve(){
    int sum=0,now=n;
    for(char ch:s){
        if(ch=='R') 
            sum++;
        else sum--;

        while(qr.size()&&(-qr.top().first)<=sum){
            int u=qr.top().second;qr.pop();
            if(!died[u]) now--,died[u]=1;
        }
        while(ql.size()&&(-ql.top().first)<=-sum){
            int u=ql.top().second;ql.pop();
            if(!died[u]) now--,died[u]=1;
        }
        cout<<now<<" ";
    }
    cout<<'\n';
}
void init(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
        cin>>b[i];
    cin>>s;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    b[0]=-INF,b[m+1]=INF;
    for(int i=1;i<=n;++i)
        died[i]=0;
    while(ql.size()) ql.pop();
    while(qr.size()) qr.pop();

    int j=1;
    for(int i=1;i<=n;++i){
        while(b[j]<a[i]) ++j;
        l[i]=a[i]-b[j-1];
        ql.push({-l[i],i});
    }
    j=m;
    for(int i=n;i>=1;--i){
        while(b[j]>a[i]) --j;
        r[i]=b[j+1]-a[i];
        qr.push({-r[i],i});
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