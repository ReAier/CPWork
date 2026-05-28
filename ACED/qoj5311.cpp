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
const int maxn=2e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
ll n,m;
ll sum[30][30],B;
struct Trie {
    struct Node { 
        ll ch[26],cnt,ed;
    }t[maxn];
#define ch(p) t[p].ch
#define cnt(p) t[p].cnt
#define ed(p) t[p].ed
    int idx,rt;
    void Insert(string s) {
        int now = rt;
        for(char c:s) {
            if(!ch(now)[c-'a']) 
                ch(now)[c-'a'] = ++idx;
            for(int i=0;i<26;++i) if(i != c-'a') 
                sum[i][c-'a'] += cnt(ch(now)[i]);
            now = ch(now)[c-'a'];
            cnt(now)++;
        }
        ed(now)++;
        B += cnt(now)-ed(now);
    }
}t;

void solve() {
    string s;
    while(m--) {
        cin>>s;
        ll ans=B;
        for(int i=0;i<26;++i) {
            for(int j=i+1;j<26;++j) 
                ans += sum[s[j]-'a'][s[i]-'a'];
        }
        cout<<ans<<'\n';
    }
}
void init() {
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;++i)
        cin>>s,t.Insert(s);
}
int main() {
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
    // while(cin>>n) {
    while(T--) {
        init();
        solve();
    }
#ifdef OPEN_TIME
    cerr<<"used: "<<(double)(clock()-StartTime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#endif
    AC
}