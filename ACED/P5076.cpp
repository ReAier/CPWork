#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
#ifndef ONLINE_JUDGE
#define OPEN_FILE
#endif
using namespace std;
const int maxn=2e4+10,INF=1e9+10,mod=1e9+7;
int n,m;
mt19937 mt;
struct node{
    int l,r,pri,val,siz;
    node(){}
    node(int Pri,int Val){pri=Pri,val=Val,siz=1;}
}t[maxn];
#define val(p) t[p].val
#define ls(p) t[p].l
#define rs(p) t[p].r
#define pri(p) t[p].pri
#define siz(p) t[p].siz
int root,idx;
int NewNode(int val){
    t[++idx]=node(mt(),val);
    return idx;
}
void pushup(int p){
    siz(p)=siz(ls(p))+siz(rs(p))+1;
}
void split(int p,int val,int &L,int &R){
    if(!p) return L=R=0,void();
    if(val(p)<=val){
        L=p;
        split(rs(p),val,rs(p),R);
    }
    else{
        R=p;
        split(ls(p),val,L,ls(p));
    }
    pushup(p);
}
int merge(int L,int R){
    if(!L||!R) return L|R;
    if(pri(L)<pri(R)){
        rs(L)=merge(rs(L),R);
        pushup(L);
        return L;
    }
    else {
        ls(R)=merge(L,ls(R));
        pushup(R);
        return R;
    }
}
int getk(int p,int k){
    if(siz(ls(p))>=k) return getk(ls(p),k);
    if(siz(ls(p))+1==k) return p;
    return getk(rs(p),k-siz(ls(p))-1);
}
int getrk(int x){
    int L,R,ans;
    split(root,x-1,L,R);
    ans=siz(L)+1;
    root=merge(L,R);
    return ans;
}
int getsub(int x){
    int L,R,ans;
    split(root,x-1,L,R);
    if(!siz(L)) ans=-2147483647;
    else ans=val(getk(L,siz(L)));
    root=merge(L,R);
    return ans;
}
int getpre(int x){
    int L,R,ans;
    split(root,x,L,R);
    if(!siz(R)) ans=2147483647;
    else ans=val(getk(R,1));
    root=merge(L,R);
    return ans;
}
void insert(int x){
    int L,R;
    split(root,x,L,R);
    root=merge(L,merge(NewNode(x),R));
}

queue<int>q;
void printTree(){
    q.push(root);
    while(q.size()){
        int p=q.front();q.pop();
        if(!p) continue;
        cout<<val(p)<<" "<<val(ls(p))<<" "<<val(rs(p))<<endl;
        q.push(ls(p));q.push(rs(p));
    }
    cout<<endl;
}

void solve(){
    int op,x;
    while(n--){
        cin>>op>>x;
        switch(op){
            case 1:
            cout<<getrk(x)<<endl;
            break;
            case 2:
            cout<<val(getk(root,x))<<endl;
            break;
            case 3:
            cout<<getsub(x)<<endl;
            break;
            case 4:
            cout<<getpre(x)<<endl;
            break;
            case 5:
            insert(x);
            break;
        }
        // printTree();
    }
}

void init(){
    cin>>n;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}