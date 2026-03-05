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
const int maxn=3e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m,cnt;
vector<bool>mp[maxn];

void solve(){
    ll cnt2=cnt-(cnt/2),now=0;
    cout<<cnt2*(cnt-cnt2)<<'\n';

    for(int i=1;i<=m;++i){
        int j=n,flg=0;
        for(;j>=1;--j){
            now+=mp[j][i];
            if(now==cnt2) {
                flg=1;
                break;
            }
        }
        if(flg){
            for(int k=1;k<j;++k) cout<<"D";
            cout<<"R";
            for(int k=j;k<=n;++k) cout<<"D";
            for(int k=i+1;k<=m;++k) cout<<"R";
            break;
        }else cout<<"R";
    }
    cout<<'\n';
}
void init(){
    cin>>n>>m;
    cnt=0;
    bool k;
    for(int i=1;i<=n;++i){
        mp[i].resize(m+10);
        for(int j=1;j<=m;++j)
            cin>>k,mp[i][j]=k,cnt+=k;
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