#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define i128 __int128_t
#define pii pair<int,int>
using namespace std;
const int maxn=3e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;

queue<int>q;
int las[maxn*10];
char ans[maxn*10];
void solve(){
    while(q.size()){
        int now=q.front();q.pop();
        int r=now/10,c=now%10;
        for(int i=max(c,1);i<=9;++i){
            int nxt=(r*10+i)%n,nid=nxt*10+i;
            if(las[nid]) break;
            q.push(nid);
            las[nid]=now;
            if(!nxt){
                while(nid){
                    ans[++m]=(nid%10)+'0';
                    nid=las[nid];
                }
                for(int i=m;i>=1;--i)
                    cout<<ans[i];
                return;
            }
        }
    }
    cout<<"-1\n";
}
void init(){
    cin>>n;
    q.push(0);
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