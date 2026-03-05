#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
string s[maxn];
struct Trie{
    struct Node{
        int ch[26];
        int id;
        int& operator[](int i){
            return ch[i];
        }
    }t[maxn];
    int idx;
    void Insert(string s,int id){
        int now=0;
        for(char c:s){
            if(!t[now][c-'a']) t[now][c-'a']=++idx;
            now=t[now][c-'a'];
        }
        t[now].id=id;
    }
    int Find(string s){
        int now=0;
        for(char c:s){
            if(!t[now][c-'a']) return 0;
            now=t[now][c-'a'];
        }
        return t[now].id;
    }
    void Init(){
        
    }
}t;
bool v[maxn];

void solve(){
    int i=1,ans=1;
    while(s[i].size()==1) v[i++]=1;
    for(;i<=n;++i){
        if(v[t.Find(s[i].substr(1,s[i].size()-1))]&&v[t.Find(s[i].substr(0,s[i].size()-1))])
            v[i]=1,ans=max(ans,(int)s[i].size());
    }
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    sort(s+1,s+1+n,[](string s1,string s2){return s1.size()<s2.size();});
    for(int i=1;i<=n;++i)
        t.Insert(s[i],i);
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