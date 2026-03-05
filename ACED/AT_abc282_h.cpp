#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=2e6+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
ll n,m;
ll a[maxn],b[maxn],sub[maxn],mia[maxn][25];
ll ans=0;
inline ll GetA(ll l,ll r){
    ll dif=r-l+1,ans=0;
    for(ll i=20;i>=0;--i) if((dif>>i)&1)
        ans=a[ans]>a[mia[l][i]]?mia[l][i]:ans,l+=1<<i;
    return ans;
}
inline ll GetB(ll l,ll r){
    return sub[r]-sub[l-1];
}
inline ll GetR(ll l,ll R,ll k){
    if(k<0) return 0;
    ll r=R+1;
    while(l<r-1){
        ll mid=(l+r)>>1;
        if(GetB(mid,R)<=k) r=mid;
        else l=mid+1;
    }
    return R+2-(GetB(l,R)<=k?l:r);
}
inline ll GetL(ll L,ll r,ll k){
    if(k<0) return 0;
    ll l=L-1;
    while(l<r-1){
        ll mid=(l+r)>>1;
        if(GetB(L,mid)<=k) l=mid;
        else r=mid-1;
    }
    return (GetB(L,r)<=k?r:l)-L+2;
}
void Divide(ll l,ll r){
    if(l>r) return;
    ll mid=GetA(l,r);
    if(mid>((l+r)>>1)){
        for(ll i=mid;i<=r;++i)
            ans+=GetR(l,mid-1,m-GetB(mid,i)-a[mid]);
    }else{
        for(ll i=mid;i>=l;--i)
            ans+=GetL(mid+1,r,m-GetB(i,mid)-a[mid]);
    }
    Divide(l,mid-1);
    Divide(mid+1,r);
}

void solve(){
    Divide(1,n);
    cout<<ans;
}

void init(){
    cin>>n>>m;
    a[0]=INF;
    for(ll i=1;i<=n;++i)   
        cin>>a[i],mia[i][0]=i;
    for(ll i=1;i<=n;++i)   
        cin>>b[i],sub[i]=sub[i-1]+b[i];
    for(ll k=1;k<=20;++k) for(ll i=1;i<=n;++i)
        mia[i][k]=a[mia[i][k-1]]>a[mia[i+(1<<(k-1))][k-1]]?
            mia[i+(1<<(k-1))][k-1]:mia[i][k-1];
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
#ifdef OPEN_TIME
    auto StartTime=clock();
#endif
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
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