#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e3+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;
struct Cards{
//桃 / P,杀 / K,闪 / D
//决斗 / F,南猪入侵 / N,万箭齐发 / W,无懈可击 / J
//猪哥连弩 / Z
};

struct AI{
    bool Friend[20],Enemy[20];
};

struct Piger{
    AI ai;
    int position;
    char Camp;
    map<char,int>Bag;
    int Health;
    bool Bow;
    Piger(char cp=' ',string bg="",int pos=0){
        Health=4,Bow=0;
        Camp=cp;
        position=pos;
        for(char ch:bg) Bag[ch]++;
    }
    void LostCard(){
        Bag.clear();
        Bow=0;
    }
    void GetCard(char cd){Bag[cd]++;}
    //濒死
    bool Dying(){
        while(Bag['P']) Bag['P']--,++Health;
        if(Health<=0) 
            return LostCard(),1;
        else return 0;
    }
    //吃桃
    bool EatPeath(){
        if(Bag['P']&&Health<4) Bag['P']--;
        else return 0;
        Health++;
        return 1;
    }
    //扣血
    bool Bleeding(int u){
        Health--;
        if(Camp=='M'&&!ai.Friend[u])
            ai.Enemy[u]=1;
        if(Health<=0) return Dying();
        return 1;
    }
    //闪
    bool BeAttacked(int u){
        ai.Enemy[u]=1;
        if(Bag['D']) {
            Bag['D']--;
            return 0;
        }else Bleeding(u);
        return 1;
    }
    //杀
    bool Attack(Piger &u){
        if(Bag['K']) {
            return u.BeAttacked(position);
        }else return 0;
    }
    bool Equip(){
        if(Bag['Z']) Bow=1;
        else return 0;
        Bag['Z']=0;
        return 1;
    }
}P[20];
int GetNextPiger(int NowPos){
    while(P[NowPos=NowPos==n?1:NowPos+1].Health<=0);
    return NowPos;
}
//En 敌意
bool Flawless(int u,int v,bool En){
    for(int i=u==n?1:u+1;i!=u;i=i==n?1:i+1){
        if(!P[i].Bag['J']) continue;
        if(En){
            if(P[i].Camp=='Z'&&P[v].Camp=='M'){
                P[i].Bag['J']--;
                return !Flawless(i,v,0);
            }else if(P[i].ai.Friend[v]) {
                P[i].Bag['J']--;
                return !Flawless(i,v,0);
            }
        }else{
            if(P[i].ai.Enemy[v]) {
                P[i].Bag['J']--;
                return !Flawless(i,v,1);
            }
        }
    }
    return 0;
}
//决斗
bool Fight(int u,int v){
    Flawless(u,v,1);
    if(P[u].Camp=='Z'&&P[v].Camp=='M'){
        if(!P[v].Bag['K']) {
            P[v].Bleeding(u);
            return 1;
        }else return P[u].Bleeding(v),0;
    }else if(P[u].Camp=='M'&&P[v].Camp=='Z'){
        P[v].Bleeding(v);
        return 1;
    }
    if(P[v].Bag['K']<P[u].Bag['K']+1){
        P[u].Bag['K']-=P[v].Bag['K']-1;
        P[v].Bleeding(v);
        P[v].Bag['K']=0;
        return 1;
    }else{
        P[v].Bag['K']-=P[u].Bag['K']+1;
        P[u].Bleeding(v);
        P[u].Bag['K']=0;
        return 0;
    }
}
//南猪入侵
bool Inveda(int u){
    if(!P[u].Bag['N']) return 0;
    P[u].Bag['N']--;
    for(int i=u==n?1:u+1;i!=u;i=i==n?1:i+1){
        if(!P[i].Bag['K']&&!Flawless(u,i,1))
            P[i].Bleeding(u);
    }
    return 1;
}
//万箭齐发
bool Archery(int u){
    if(!P[u].Bag['W']) return 0;
    P[u].Bag['W']--;
    for(int i=u==n?1:u+1;i!=u;i=i==n?1:i+1){
        if(!P[i].Bag['D']&&!Flawless(u,i,1))
            P[i].Bleeding(u);
    }
    return 1;
}
struct CardHeap{
    char H[maxn];
    int now,tail;
    char GetCard(){return now==tail?H[now]:H[now++];}
    void ReadCard(){
        tail=m;now=1;
        for(int i=1;i<=tail;++i)
            cin>>H[i];
    }
}Hp;

void solve(){
    int WinFlag=0;
    while(!WinFlag){
        for(int i=1;i<=n;++i){
            Piger &Now=P[i];
            if(Now.Health<=0) continue;
            
        }
    }
}

void init(){
    cin>>n>>m;
    string str,bg;
    char ch;
    for(int i=1;i<=n;++i){
        cin>>str;
        bg.clear();
        for(int j=1;j<=4;++j) 
            cin>>ch,bg.push_back(ch);
        P[i]=(Piger(str.front(),bg,i));
    }
    Hp.ReadCard();
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