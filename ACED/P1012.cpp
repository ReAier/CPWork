#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int MAXN=1e6+10,INF=1e9+10;
int n,m;

string a[100];
bool cmp(const string &x,const string &y){
    return x+y>y+x;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
}
void solve(){
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i) cout<<a[i];
}

int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}