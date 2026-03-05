#include<bits/stdc++.h>
#define AC return 0;
using namespace std;
const int maxn = 1e6+10;
const int Inf=1e9+10;
struct pos{
    int x,y;
    pos(){}
    pos(int _x,int _y){x=_x,y=_y;}
    pos operator+(const pos &a) const{return pos(x+a.x,y+a.y);}
    bool operator==(const pos &a) const{return x==a.x&&y==a.y;}
};


int n,m;
int vis[15][15][15][15];
char mp[15][15];
const pos up=pos(-1,0),dw=pos(1,0),rt=pos(0,1),lf=pos(0,-1);
pos Fpos,Cpos,Fvec=up,Cvec=up;
pos swih(pos x){
    if(x==up)
        return rt;
    else if(x==rt)
        return dw;
    else if(x==dw)
        return lf;
    else 
        return up;
}
pos move(pos x,pos &v){
    pos y=x+v;
    if(mp[y.x][y.y]=='*'||!(mp[y.x][y.y]))return v=swih(v),x;
    return y;
}

void print(pos x){
    printf("%d %d\n",x.x,x.y);
}
void p(){
    cout<<"Fpos: ";
    print(Fpos);
    cout<<"Cpos: ";
    print(Cpos);
    cout<<endl;
}

int main(){
    for(int i=1;i<=10;++i)
        for(int j=1;j<=10;++j){
            cin>>mp[i][j];
            if(mp[i][j]=='F') Fpos=pos(i,j);
            else if(mp[i][j]=='C') Cpos=pos(i,j);
        }
    // p();
    int step=0;
    while(++step){
        if(vis[Fpos.x][Fpos.y][Cpos.x][Cpos.y]>4) return printf("0"),0;
        vis[Fpos.x][Fpos.y][Cpos.x][Cpos.y]++;
        Fpos=move(Fpos,Fvec);
        Cpos=move(Cpos,Cvec);
        // p();
        if(Fpos==Cpos) break;
    }
    printf("%d",step);
    AC
}