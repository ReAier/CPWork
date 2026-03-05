#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=6000+10,INF=1e9+10,mod=1e9+7;
int n,m;
int a[maxn];

ll Cx2(ll x){
    if(x<2) return 0;
    return (x*(x-1)/2)%mod;
}

void solve(){
    ll ans=0;
    for(int i=1;i<=5000;++i){
        if(a[i]<2) continue;
        for(int j=1;j<=(i/2);++j){
            int k=i-j;
            if(j==k){
                ans+=Cx2(a[i])*Cx2(a[j])%mod;
                ans%=mod;
            }
            else{
                ans+=Cx2(a[i])*a[j]*a[k]%mod;
                ans%=mod;
            }
        }
    }
    cout<<ans%mod;
}
void init(){
    cin>>n;
    int b;
    for(int i=1;i<=n;++i){
        cin>>b;
        a[b]++;
    }
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}