#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn = 1e6+10;
ll n,m;
ll sum[maxn],tag[maxn];

void add_tag(ll s,ll l,ll r,ll w){
    sum[s]+=(r-l+1)*w;
    tag[s]+=w;
}
void push_tag(ll s,ll l,ll r){
    ll mid=(l+r)>>1;
    add_tag(s<<1,l,mid,tag[s]);
    add_tag(s<<1|1,mid+1,r,tag[s]);
    tag[s]=0;
}
void build(ll s,ll l,ll r){
    if(l==r) {cin>>sum[s];return;}
    ll mid=(l+r)>>1;
    build(s<<1,l,mid);
    build(s<<1|1,mid+1,r);
    sum[s]=sum[s<<1]+sum[s<<1|1];
}
void add(ll s,ll l,ll r,ll L,ll R,ll w){
    if(r<L||l>R) return;
    push_tag(s,l,r);
    if(L<=l&&R>=r) {add_tag(s,l,r,w); return;}
    ll mid=(l+r)>>1;
    add(s<<1,l,mid,L,R,w);
    add(s<<1|1,mid+1,r,L,R,w);
    sum[s]=sum[s<<1]+sum[s<<1|1];
}
ll query(ll s,ll l,ll r,ll L,ll R){
    if(r<L||l>R) return 0;
    push_tag(s,l,r);
    if(L<=l&&R>=r) {return sum[s];}
    ll mid=(l+r)>>1;
    ll q=0;
    q+=query(s<<1,l,mid,L,R);
    q+=query(s<<1|1,mid+1,r,L,R);
    return q;
}


int main(){
    cin>>n>>m;
    build(1,1,n);
    ll l,r,k,w;
    while (m--){
        cin>>k>>l>>r;
        if(k==1){
            cin>>w;
            add(1,1,n,l,r,w);
        }
        else
            cout<<query(1,1,n,l,r)<<endl;
    }

    return 0;
}