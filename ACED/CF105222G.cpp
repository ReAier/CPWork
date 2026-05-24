#include<bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i = 1;i <= n;++ i)
using ll = long long;
const ll inf = 2e18;
const int N = 1e7 + 10,P = 1e9 + 7;
int n,m;
int a[N];
struct Trie01{
  struct Node{
    int ch[2],pos;
  }t[N];
#define ch(p) t[p].ch
#define pos(p) t[p].pos
  int idx=1;
  void Add(int x,int pos){
    int p=1;
    for(int i=30;i>=0;--i){
      bool bi=(x>>i)&1;
      if(!ch(p)[bi]) ch(p)[bi]=++idx;
      p=ch(p)[bi];
    }
    pos(p)=pos;
  }
  pair<int,int> Query(int x,int k){
    int p=1,ans=0;
    for(int i=30;i>=0;--i){
      bool bi=(x>>i)&1;
      if(ch(p)[bi^k]) 
        ans+=k*(1<<i),p=ch(p)[bi^k];
      else ans+=(k^1)*(1<<i),p=ch(p)[bi^k^1];
    }
    return {ans,pos(p)};
  }
}t;

int Query(int x,int k){
  auto[mx,mxp]=t.Query(x,1);
  auto[mi,mip]=t.Query(x,0);
  if(mx<k||mi>k) return -1;
  if(mx==k) return min(mxp,n-1);
  if(mi==k) return min(mip,n-1);
  int l=min(mxp,mip),r=max(mxp,mip);
  while(l<r-1){
    int mid=l+r>>1;
    if(((a[mid]^x)>k)==(mxp<mip))
      l=mid;
    else r=mid;
  }
  return l;
}

void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    cin>>a[i],t.Add(a[i],i);
  while(m--){
    int x,k;
    cin>>x>>k;
    cout<<Query(x,k)<<'\n';
  }
}

int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int _ = 1;
  //cin >> _;
  while(_--)solve();
  return 0;
}