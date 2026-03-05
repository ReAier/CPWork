#include<bits/stdc++.h>
#define AC return 0;
#define lc(x) tr[x].lc
#define rc(x) tr[x].rc
#define val(x) tr[x].val
#define size(x) tr[x].size
#define pri(x) tr[x].pri
using namespace std;
const int maxn = 1e6+10;
int n,m,idx,root;

struct node{
    int lc,rc,val,pri,size;
}tr[maxn];

void push_up(int x){
    tr[x].size=tr[lc(x)].size+tr[rc(x)].size+1;
}

void split(int p,int val,int &L,int &R){
    if(!p){
        L=R=0;
        return;
    }
    if(val(p)<=val){
        L=p;
        split(rc(p),val,rc(p),R);
    }
    else{
        R=p;
        split(lc(p),val,L,lc(p));
    }
    push_up(p);
}

int merge(int L,int R){
    if(!L||!R) return L|R;
    if(pri(L)<pri(R)){
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

int new_node(int val){
    tr[++idx].pri=rand();
    tr[idx].size=1;
    tr[idx].val=val;
    return idx;
}

void ins(int val){
    int L,R;
    split(root,val,L,R);
    root=merge(L,merge(new_node(val),R));
}


void del(int val){
    int L,R,mi;
    split(root,val,L,R);
    split(L,val-1,L,mi);
    mi=merge(lc(mi),rc(mi));
    root =merge(L,merge(mi,R));
}

int get_k(int p, int k){
    if(size(lc(p))+1==k) return p;
    if(size(lc(p))+1>k) return get_k(lc(p),k);
    return get_k(rc(p),k-size(lc(p))-1);
}

int get_rank(int val){
    int L,R,res;
    split(root,val-1,L,R);
    res=size(L)+1;
    root=merge(L,R);
    return res;
}

int get_val(int rk){
    return val(get_k(root,rk));
}


int find_per(int val){
    int L,R,res;
    split(root,val-1,L,R);
    res=val(get_k(L,size(L)));
    root=merge(L,R);
    return res;
}

int find_sub(int val){
    int L,R,res;
    split(root,val,L,R);
    res=val(get_k(R,1));
    root=merge(L,R);
    return res;
}

void dfs(int p){
    if(!p) return;
    cout<<val(p)<<" "<<val(lc(p))<<" "<<val(rc(p))<<endl;
    dfs(lc(p));dfs(rc(p));
}

void print_tree(int p=0){
    if(!p) p=root;
    dfs(p);
}
int main(){
    scanf("%d",&n);
    int opt,k;
    while(n--){
        scanf("%d%d",&opt,&k);
        switch (opt)
        {
        case 1:
            ins(k);
            break;
        case 2:
            del(k);
            break;
        case 3:
            printf("%d\n",get_rank(k));
            break;
        case 4:
            printf("%d\n",get_val(k));
            break;
        case 5:
            printf("%d\n",find_per(k));
           // print_tree();
            break;
        case 6:
            printf("%d\n",find_sub(k));
           // print_tree();
            break;
        }
    }
    AC
}