#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 1e6+10;
int n,m,mo;
int sum[maxn],tag_a[maxn],tag_m[maxn],len[maxn];
void push_up(int s){
    sum[s]=sum[s<<1]+sum[s<<1|1];
    sum[s]%=mo;
}

void add_tag(int s,int add,int mul){
    sum[s]=(sum[s]*mul+len[s]*add)%mo;
    tag_m[s]=tag_m[s]*mul%mo;
    tag_a[s]=(tag_a[s]*mul+add)%mo;
}

void push_down(int s){
    add_tag(s<<1,tag_a[s]%mo,tag_m[s]%mo);
    add_tag(s<<1|1,tag_a[s]%mo,tag_m[s]%mo);
    tag_a[s]=0;
    tag_m[s]=1;
}

void build(int s,int l,int r){
    tag_m[s]=1;
    len[s]=r-l+1;
    if(l==r){
        scanf("%lld",&sum[s]);
        sum[s]%=mo;
        return;
    }
    int mid=(l+r)>>1;
    build(s<<1,l,mid);
    build(s<<1|1,mid+1,r);
    push_up(s);
}

int query(int s,int l,int r,int L,int R){
    if(l>R||r<L) return 0;
    if(l>=L&&R>=r) return sum[s]%mo;
    int mid=(l+r)>>1,res=0;
    push_down(s);
    res+=query(s<<1,l,mid,L,R);
    res+=query(s<<1|1,mid+1,r,L,R);
    push_up(s);
    return res%mo;
}

void add_a(int s,int l,int r,int L,int R,int k){
  //  cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(l>R||r<L) return;
    if(l>=L&&R>=r) return add_tag(s,k,1);
    int mid=(l+r)>>1;
    push_down(s);
    add_a(s<<1,l,mid,L,R,k);
    add_a(s<<1|1,mid+1,r,L,R,k);
    push_up(s);
}

void add_m(int s,int l,int r,int L,int R,int k){
    if(l>R||r<L) return;
    if(l>=L&&R>=r) return add_tag(s,0,k);
    int mid=(l+r)>>1;
    push_down(s);
    add_m(s<<1,l,mid,L,R,k);
    add_m(s<<1|1,mid+1,r,L,R,k);
    push_up(s);
}

void print_tree(){
    for(int i=1;i<=9;++i) cout<<sum[i]<<" "<<tag_a[i]<<" "<<tag_m[i]<<endl;
    cout<<endl;
}

signed main(){
#ifndef ONLINE_JUDGE 
    freopen("P3373_1.in","r", stdin);
    freopen("P3373.out","w", stdout);
#endif
    scanf("%lld%lld",&n,&mo);
    build(1,1,n);
    int x,y,k,opt;
    scanf("%lld",&m);
    while (m--){
        scanf("%lld%lld%lld",&opt,&x,&y);
        if(opt==1){
            scanf("%lld",&k);
            add_m(1,1,n,x,y,k%mo);
        }
        else if(opt==2){
            scanf("%lld",&k);
            add_a(1,1,n,x,y,k%mo);
        }
        else{
            printf("%lld\n",query(1,1,n,x,y));
        }
    }

    return 0;
}