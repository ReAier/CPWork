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
vector<int>a[maxn];
set<int>vis,ban;
vector<int>tmpx,tmpy,ans,tmp;

vector<int> GetTmp(vector<int>&x){
    vis.clear();
    tmp.clear();
    for(int u:x){
        if(vis.count(u)||ban.count(u)) 
            continue;
        tmp.push_back(u);
        vis.insert(u);
    }
    return tmp;
}
bool cmp(vector<int>&x,vector<int>&y){
    tmpx.clear(),tmpy.clear();
    tmpx=GetTmp(x),tmpy=GetTmp(y);
    for(int i=0;i<min(tmpx.size(),tmpy.size());++i)
        if(tmpx[i]<tmpy[i]) 
            return 1;
        else if(tmpx[i]>tmpy[i]) 
            return 0;
    return tmpx.size()<=tmpy.size();
}

void solve(){
    int now=0;
    for(int i=1;i<=n;++i){
        now=i;
        for(int j=i+1;j<=n;++j)
            if(cmp(a[j],a[now]))
                now=j;
        swap(a[i],a[now]);
        for(int u:GetTmp(a[i])) 
            ans.push_back(u),ban.insert(u);
    }
    for(int u:ans)
        cout<<u<<" ";
    cout<<'\n';
}
void init(){
    cin>>n;
    ans.clear();
    ban.clear();
    int sz,u;
    for(int i=1;i<=n;++i){
        cin>>sz;
        a[i].clear();
        while(sz--) cin>>u,a[i].push_back(u);
        reverse(a[i].begin(),a[i].end());
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