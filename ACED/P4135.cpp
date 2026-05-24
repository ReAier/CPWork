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
const int maxn=1e5+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m,c;
const int Blen=350;
int a[maxn],s[maxn][Blen+10],p[Blen+10][Blen+10],Bnum;
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
    for(int u:st){
        int cntu=cnt[u]+max(0,s[u][qr-1]-s[u][ql]);
        if((s[u][qr-1]>s[u][ql])&&(cntu&1)&&(((s[u][qr-1]-s[u][ql])&1)==0))
            --ans;
        else if((((cntu-cnt[u])&1)||(cntu==cnt[u]))&&((cntu&1)==0))
            ++ans;
    }
    for(int u:st)
        cnt[u]=0;
    st.clear();
    return ans+p[ql+1][qr-1];
}

void solve(){
    memset(cnt,0,sizeof(cnt));
    int l,r,lastans=0;
    while(m--){
        cin>>l>>r;
        l=(l+lastans)%n;
        r=(r+lastans)%n;
        if(l>r) swap(l,r);
        cout<<(lastans=Query(l+1,r+1))<<'\n';
    }
}
void init(){
    cin>>n>>c>>m;
    Bnum=n/Blen+bool(n%Blen);
    for(int i=1;i<=n;++i)
        cin>>a[i];

    for(int i=1;i<=Bnum;++i){
        for(int j=1;j<=c;++j)
            s[j][i]+=s[j][i-1];
        for(int j=(i-1)*Blen+1;j<=min(n,i*Blen);++j)
            s[a[j]][i]++;
    }

    for(int i=1;i<=Bnum;++i) {
        memset(cnt,0,sizeof(cnt));
        mx=0;
        for(int j=i;j<=Bnum;++j) {
            for(int k=(j-1)*Blen+1;k<=min(n,j*Blen);++k) {
                cnt[a[k]]++;
                if((cnt[a[k]]&1)&&(cnt[a[k]]!=1))
                    --mx;
                else if(cnt[a[k]]!=1) ++mx;
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