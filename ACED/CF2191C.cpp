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
string s;
bool a[maxn];

int o,z;
bool Sorted(){
    bool one=0;
    for(char ch:s){
        if(ch=='1') one=1;
        if(one&&ch=='0')
            return 0;
    }return 1;
}
vector<int>ans;
void solve(){
    if(!Sorted()) {
        cout<<"Alice\n";
        sort(a,a+n);
        for(int i=0;i<n;++i) if(a[i]!=(s[i]=='1'))
            ans.push_back(i+1);
        cout<<ans.size()<<'\n';
        for(int u:ans)
            cout<<u<<" ";
        cout<<'\n';
    }else cout<<"Bob\n";
}
void init(){
    cin>>n>>s;
    for(int i=0;i<n;++i)
        a[i]=s[i]=='1';
    ans.clear();
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