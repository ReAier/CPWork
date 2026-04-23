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
string s;
struct ACAM{
    struct Node{
        int ch[26],fal,cnt;
    }t[maxn];
#define ch(p) t[p].ch
#define fal(p) t[p].fal
#define cnt(p) t[p].cnt
    vector<int>e[maxn];
    int pos[maxn],idx;
    void Insert(const string &s,int id){
        int now=0;
        for(char ch:s){
            if(!ch(now)[ch-'a'])
                ch(now)[ch-'a']=++idx;
            now=ch(now)[ch-'a'];
        }
        pos[id]=now;
    }
    void GetFail(){
        queue<int>q;
        for(int i=0;i<26;++i) if(ch(0)[i])
            q.push(ch(0)[i]);
        while(q.size()){
            int u=q.front();q.pop();
            for(int i=0;i<26;++i){
                int v=ch(u)[i];
                if(v) fal(v)=ch(fal(u))[i],q.push(v);
                else ch(u)[i]=ch(fal(u))[i];
            }
        }
        for(int i=1;i<=idx;++i)
            e[fal(i)].push_back(i);
    }
    void Dfs(int u){
        for(int v:e[u]) 
            Dfs(v),cnt(u)+=cnt(v);
    }
    vector<int> Query(const string &s){
        int now=0;
        for(char ch:s)
            now=ch(now)[ch-'a'],cnt(now)++;
        Dfs(0);
        vector<int>ans;
        for(int i=1;i<=n;++i)
            ans.push_back(cnt(pos[i]));
        return ans;
    }
}t;

void solve(){
    auto ans=t.Query(s);
    for(int u:ans)
        cout<<u<<'\n';
}
void init(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s,t.Insert(s,i);
    t.GetFail();
    cin>>s;
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