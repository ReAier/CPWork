#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e5+10,INF=1e9+10,mod=1e9+7;
int n;
string a,b;
string x[10],y[10];


map<string,bool>inq;
queue<pair<string,int>>q;

void solve(){
    int ans=INF;
    q.push({a,0});
    while(q.size()){
        auto s=q.front().first;
        auto dep=q.front().second;
        q.pop();
        if(s==b){
            ans=dep;
            break;
        }
        if(dep==10) break;
        for(int i=0;i<=s.size();++i) for(int j=1;j+i<=s.size();++j) for(int k=1;k<=n;++k) if(x[k]==s.substr(i,j)) {
            string news=s.substr(0,i)+y[k]+s.substr(i+j,s.size()-i-j);
                if(!inq[news]){
                    q.push({news,dep+1});
                    inq[news]=1;
                }
        }
    }
    if(ans==INF) printf("NO ANSWER!");
    else printf("%d",ans);
}
void init(){
    cin>>a>>b;
    while(cin>>x[++n]) cin>>y[n];
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}