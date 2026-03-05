#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;
int a[maxn];
struct Node{
    int maxnum,len;
    Node(){}
    Node(int a,int b){maxnum=a,len=b;}
    bool operator<(const Node &x)const{
        if(len!=x.len) return len>x.len;
        return maxnum>x.maxnum;
    }
};
priority_queue<Node>q;
queue<Node>tmpq;

void solve(){
    int ans=INF;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        while(q.size()){
            Node x=q.top();
            q.pop();
            if(a[i]-x.maxnum>1){
                ans=min(ans,x.len);
                // break;
                // 数据好水，这里多给break都有70
            }else if(a[i]-x.maxnum==1){
                q.push(Node(a[i],x.len+1));
                break;
            }else{
                tmpq.push(x);
            }
        }
        if(!q.size()){
            q.push(Node(a[i],1));
        }
        while(tmpq.size()){
            q.push(tmpq.front());
            tmpq.pop();
        }
    }
    while(q.size()){
        ans=min(ans,q.top().len);
        q.pop();
    }
    cout<<ans;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}