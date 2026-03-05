#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=4e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;
double a,b,r;
int dcmp(double x){
    return fabs(x)<eps?0:(x>0?1:-1);
}
struct Point{
    double x,y;
    Point(double _x=0,double _y=0):x(_x),y(_y){}
    Point operator-(Point u){
        return {x-u.x,y-u.y};
    }
    Point operator+(Point u){
        return {x+u.x,y+u.y};
    }
    double len(){
        return sqrt(x*x+y*y);
    }
    bool operator==(Point u){
        return (*this-u).len()<eps;
    }
    double cross(Point u){
        return x*u.y-y*u.x;
    }
    double angle(){
        return atan2(y,x);
    }
    Point rotate(double rad) const {
        return {x * cos(rad) - y * sin(rad), 
                     x * sin(rad) + y * cos(rad)};
    }
};

Point st[maxn],ve[maxn];
int top,sz;
double Graham(){
    for(int i=1;i<=sz;++i){
        Point u=ve[i];
        while(top>=2){
            Point v=st[top],w=st[top-1];
            if(dcmp((u-v).cross(v-w))<=0)
                break;
            top--;
        }st[++top]=u;
    }
    st[0]=st[top];
    double ans=0;
    for(int i=1;i<=top;++i) 
        ans+=(st[i]-st[i-1]).len();
    return ans;
}

void solve(){
    for(int i=1;i<sz;++i){
        if((ve[i].y==ve[m].y)?ve[i].x<ve[m].x:ve[i].y<ve[m].y) 
            m=i;
    }swap(ve[1],ve[m]);

    sort(ve+2,ve+1+sz,[](Point x,Point y){
        x=x-ve[1],y=y-ve[1];
        int tmp=dcmp(x.cross(y));
        if(dcmp(tmp)==0)
            return x.len()<y.len();
        return tmp>0;
    });
    sz=unique(ve+1,ve+sz+1)-ve-1;

    printf("%.2lf",Graham()+2*Pi*r);
}

void init(){
    cin>>n>>b>>a>>r;
    a=(a/2)-r,b=(b/2)-r;
    double x,y,th;
    m=1;
    for(int i=1;i<=n;++i){
        cin>>x>>y>>th;
        ve[++sz]=(Point(x,y)+Point(a,b).rotate(th));
        ve[++sz]=(Point(x,y)+Point(a,-b).rotate(th));
        ve[++sz]=(Point(x,y)+Point(-a,b).rotate(th));
        ve[++sz]=(Point(x,y)+Point(-a,-b).rotate(th));
    }
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