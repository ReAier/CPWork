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
const int maxn=40000+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;

const int Blen=200;
int a[maxn],s[maxn][Blen+10],p[Blen+10][Blen+10],Bnum;
map<int,int>mp;
int b[maxn],idx;
int cnt[maxn],mx;

vector<int>st;

int Query(int l,int r){
    int ql=(l-1)/Blen+1,qr=min((r-1)/Blen+1,Bnum),ans=0;
    for(int i=l;i<=min(ql*Blen,r);++i){
        if(!cnt[a[i]])
            st.push_back(a[i]);
        cnt[a[i]]++;
    }
    if(ql!=qr) for(int i=(qr-1)*Blen+1;i<=r;++i){
        if(!cnt[a[i]])
            st.push_back(a[i]);
        cnt[a[i]]++;
    }
    if(ql+1<=qr-1&&!cnt[p[ql+1][qr-1]])
        st.push_back(p[ql+1][qr-1]);
    for(int u:st){
        int cntu=cnt[u]+max(0,s[u][qr-1]-s[u][ql]);
        int cntv=cnt[ans]+max(0,s[ans][qr-1]-s[ans][ql]);
        if(cntu>cntv||(cntu==cntv&&u<ans))
            ans=u;
    }
    for(int u:st)
        cnt[u]=0;
    st.clear();
    return b[ans];
}

void solve(){
    memset(cnt,0,sizeof(cnt));
    int l,r,lastans=0;
    while(m--){
        cin>>l>>r;
        l=(l+lastans-1)%n;
        r=(r+lastans-1)%n;
        if(l>r) swap(l,r);
        cout<<(lastans=Query(l+1,r+1))<<'\n';
    }
}
int c[maxn];
void init(){
    cin>>n>>m;
    Bnum=n/Blen+bool(n%Blen);
    for(int i=1;i<=n;++i)
        cin>>a[i],c[i]=a[i];
    sort(c+1,c+1+n);
    for(int i=1;i<=n;++i) if(!mp[c[i]]) 
        mp[c[i]]=++idx,b[idx]=c[i];
    for(int i=1;i<=n;++i)
        a[i]=mp[a[i]];

    for(int i=1;i<=Bnum;++i){
        for(int j=1;j<=idx;++j)
            s[j][i]+=s[j][i-1];
        for(int j=(i-1)*Blen+1;j<=min(n,i*Blen);++j)
            s[a[j]][i]++;
    }

    for(int i=1;i<=Bnum;++i) {
        memset(cnt,0,sizeof(cnt));
        for(int j=i;j<=Bnum;++j) {
            for(int k=(j-1)*Blen+1;k<=min(n,j*Blen);++k) {
                cnt[a[k]]++;
                if(cnt[a[k]]>cnt[mx]||(cnt[a[k]]==cnt[mx]&&a[k]<mx))
                    mx=a[k];
            }
            p[i][j]=mx;
        }
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