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
int a[maxn];
vector<int>Ds;
char ans[maxn];

int GetW(int x){
    int ans=0;
    while(x) {
        if(x&1) 
            return ans;
        x>>=1;
        ++ans;
    }
    return 0;
}

void solve(){
    for(int d:Ds){
        bool flg=1;
        for(int i=1;i<=d&&flg;++i){
            int now=a[i];
            for(int j=i+d;j<=n;j+=d) 
                now&=a[j];
            if(now){
                char ch=GetW(now)+'a';
                for(int j=i;j<=n;j+=d) 
                    ans[j]=ch;
            }else flg=0;
        }
        if(flg) break;
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i];
    cout<<'\n';
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        a[i]=0;
    string s;
    for(int i=1;i<=m;++i){
        cin>>s;
        for(int j=0;j<n;++j)
            a[j+1]|=(1<<(s[j]-'a'));
    }
    Ds.clear();
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            Ds.push_back(i);
            Ds.push_back(n/i);
        }
    }
    sort(Ds.begin(),Ds.end());
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