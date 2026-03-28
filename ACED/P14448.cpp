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
int n,m;
string s;
int sumC[maxn],sumW[maxn],sumP[maxn];
int mp[100];
char mp2[100];

bool Chack(int l,int r){
    if(r<l) return 0;
    int C=sumC[r]-sumC[l-1],W=sumW[r]-sumW[l-1],P=sumP[r]-sumP[l-1];
    int vc=C-W-P+(l>1?s[l-2]=='C':0)+(r<n?s[r]=='C':0);
    int vw=W-C-P+(l>1?s[l-2]=='W':0)+(r<n?s[r]=='W':0);
    int vp=P-C-W+(l>1?s[l-2]=='P':0)+(r<n?s[r]=='P':0);
    return vc<=1&&vw<=1&&vp<=1;
}
void Print(int l,int r){
    int las=mp[(l>1?s[l-2]:'#')],nx=mp[(r<n?s[r]:'#')];
    int C[3]={sumC[r]-sumC[l-1],sumW[r]-sumW[l-1],sumP[r]-sumP[l-1]};
    for(int i=l;i<=r;++i){
        int k[3]={0,1,2};
        sort(k,k+3,[C,nx](int x,int y){return C[x]==C[y]?(x==nx||y!=nx):C[x]>C[y];});
        if(k[0]==las)
            cout<<mp2[k[1]],--C[k[1]],las=k[1]; 
        else cout<<mp2[k[0]],--C[k[0]],las=k[0];
    }
}

void solve(){
    if(!Chack(1,n)) 
        return cout<<"Impossible\n",void();
    int l=-1,r=-1;
    for(int i=1;i<=n;++i) if(s[i-1]==s[i]){
        l=i;
        break;
    }
    if(l==-1) 
        return cout<<"Beautiful\n",void();
    for(int i=n;i>=1;--i) if(s[i-1]==s[i]){
        r=i+1;
        break;
    }
    int j=r-1,mil=1,mir=n;
    for(int i=1;i<=l+1;++i){
        while(j<=n&&!Chack(i,j))
            ++j;
        if(mir-mil>j-i&&j<=n)
            mir=j,mil=i;
    }
    cout<<"Possible\n";
    cout<<mil<<" "<<mir<<"\n";
    for(int i=1;i<mil;++i)
        cout<<s[i-1];
    Print(mil,mir);
    for(int i=mir+1;i<=n;++i)
        cout<<s[i-1];
    cout<<'\n';
}
void init(){
    cin>>n>>s;
    for(int i=1;i<=n;++i){
        sumC[i]=sumC[i-1]+(s[i-1]=='C');
        sumW[i]=sumW[i-1]+(s[i-1]=='W');
        sumP[i]=sumP[i-1]+(s[i-1]=='P');
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
    mp['C']=0,mp['W']=1,mp['P']=2,mp['#']=90;
    mp2[0]='C',mp2[1]='W',mp2[2]='P';
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