#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;

int tr[maxn][27],num[maxn],idx=1;
bool used[maxn];
void addstr(string s){
    int idnow=1;
    for(auto i :s){
        if(!tr[idnow][i-'a'+1]) tr[idnow][i-'a'+1]=++idx;
        idnow=tr[idnow][i-'a'+1];
    }
    num[idnow]++;
}

int chack(string s){
    int idnow=1;
    for(auto i:s){
        if(!tr[idnow][i-'a'+1]) return 0;
        idnow=tr[idnow][i-'a'+1];
    }
    if(!num[idnow]) return 0;
    if(used[idnow]) return 2;
    return used[idnow]=1;
}

void solve(){
    string s;
    while(m--){
        cin>>s;
        switch(chack(s)){
            case 0:
            cout<<"WRONG"<<endl;
            break;
            case 1:
            cout<<"OK"<<endl;
            break;
            case 2:
            cout<<"REPEAT"<<endl;
            break;
        }
    }
}

void init(){
    cin>>n;
    string s;
    for(int i=1;i<=n;++i) cin>>s,addstr(s);
    cin>>m;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
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