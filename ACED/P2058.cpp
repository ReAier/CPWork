#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=5e5+10,INF=1e9+10,mod=1e9+7;
int n,m;
int con[maxn],connum,t[maxn];
map<int,int>mp[maxn];

void solve(){
    int i=1;
    int kk;
    for(int j=1;j<=n;++j){
        cin>>t[j];
        while(t[j]-t[i]>=86400){
            for(auto k:mp[i]){
                con[k.first]-=k.second;
                if(!con[k.first]) connum--;
            }
            ++i;
        }
        cin>>kk;
        while(kk--){
            int ki;
            cin>>ki;
            mp[j][ki]++;
            if(!con[ki]) connum++;
            con[ki]++;
        }
        cout<<connum<<endl;
    }
}

void init(){
    cin>>n;
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}