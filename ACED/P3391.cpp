#include<bits/stdc++.h>
#define AC return 0;
#define lc(x) tr[x].lc
#define rc(x) tr[x].rc
#define val(x) tr[x].val
#define size(x) tr[x].size
#define pri(x) tr[x].pri
#define tag(x) tr[x].tag
using namespace std;
const int maxn = 1e6+10;
int n,m,root,idx;
struct node
{
    int lc,rc,val,pri,size;
    bool tag=0;
}tr[maxn];

int new_node(int val){
    val(++idx)=val;
    size(idx)=1;
    pri(idx)=rand();
    return idx;
}

void add_tag(int p){
    tag(p)^=1;
    swap(lc(p),rc(p));
}
void push_up(int p){
    size(p)=size(lc(p))+size(rc(p))+1;
}

void push_down(int p){
    if(!tag(p)) return;
    add_tag(lc(p));
    add_tag(rc(p));
    tag(p)=0;
}

void split(int p,int siz,int &L,int &R){
    if(!p) return L=R=0,void();
    push_down(p);
    if(size(lc(p))+1<=siz){
        L=p;
        split(rc(p),siz-size(lc(p))-1,rc(p),R);
    }
    else {
        R=p;
        split(lc(p),siz,L,lc(p));
    }
    push_up(p);
}
int merge(int L,int R){
    if(!L||!R) return L|R;
    push_down(L);
    push_down(R);
    if(pri(L)>pri(R)){
        rc(L)=merge(rc(L),R);
        push_up(L);
        return L;
    }
    else{
        lc(R)=merge(L,lc(R));
        push_up(R);
        return R;
    }
}

void inv(int l,int r){
    int L,R,mi;
    split(root,l-1,L,mi);
    split(mi,r-l+1,mi,R);
   // cout<<size(L)<<" "<<size(mi)<<" "<<size(R)<<endl;
    add_tag(mi);
    root=merge(L,merge(mi,R));
}

void print_tree(int p){
    if(!p) return;
    push_down(p);
    print_tree(lc(p));
    cout<<val(p)<<" ";
    print_tree(rc(p));
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        root=merge(root,new_node(i));
    int l,r;
    while(m--){
        cin>>l>>r;
        inv(l,r);
    }
    print_tree(root);
    AC
}