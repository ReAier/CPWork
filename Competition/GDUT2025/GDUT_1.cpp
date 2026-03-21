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
ll n,m;
string s;
__int128_t a[5];
int mp[100];

__int128_t pow10(int x){
    if(x>18) return n+1;
    __int128_t ans=1,a=10;
    while(x){
        if(x&1)
            ans=ans*a;
        x>>=1;
        a*=a;
    }
    return ans;
}

void solve(){ 
    for(int G=0;G<=9&&G*a[1]<=n;++G){
        for(int D=0;D<=9&&D*a[2]<=n;++D){
            for(int U=0;U<=9&&U*a[3]<=n;++U){
                for(int T=0;T<=9&&T*a[4]<=n;++T){
                    __int128_t res=G*a[1]+D*a[2]+U*a[3]+T*a[4];
                    if(res==n){
                        cout<<"YES\n";
                        cout<<G<<" "<<D<<" "<<U<<" "<<T<<'\n';
                        return;
                    }
                }
            }
        }
    }
    cout<<"NO\n";
}
void init(){
    cin>>s>>n;
    memset(a,0,sizeof(a));
    mp['G']=1,mp['D']=2,mp['U']=3,mp['T']=4;
    int las=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='+'){
            for(int j=las;j<i;++j){
                a[mp[s[j]]]+=pow10(i-j-1);
                if(a[mp[s[j]]]>n)
                    a[mp[s[j]]]=n+1;
            }
            las=i+1;
        }
    }
    for(int j=las;j<s.size();++j) {
        a[mp[s[j]]]+=pow10(s.size()-j-1); 
        if(a[mp[s[j]]]>n)
            a[mp[s[j]]]=n+1;
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
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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