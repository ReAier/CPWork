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
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8,Pi=acos(-1);
int n,m;

inline int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    friend istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    bool operator==(const Point& p) const {
        return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
    double length() const {
        return sqrt(x * x + y * y);
    }
    double angle() const {
        return atan2(y, x);
    }
}a[maxn],st[maxn];
int top;

void solve(){
    for(int i=1;i<=n;++i){
        while(top>=2){
            Point u=st[top],v=st[top-1];
            if(dcmp((a[i]-u).cross(u-v))<=0)
                break;
            top--;
        }st[++top]=a[i];
    }
    double ans=0;
    st[0]=st[top];
    for(int i=1;i<=top;++i)
        ans+=(st[i]-st[i-1]).length();
    printf("%.2lf",ans);
}
void init(){
    cin>>n;
    a[m]={INF,INF};
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if((a[i].y==a[m].y)?a[i].x<a[m].x:a[i].y<a[m].y)
            m=i;
    }
    swap(a[m],a[1]);
    sort(a+2,a+n+1,[]( Point x, Point y){
        x=x-a[1],y=y-a[1];
        if(dcmp(x.angle()-y.angle())==0) 
            return x.length()<y.length();
        return x.angle()<y.angle();
    });
    n=unique(a+1,a+1+n)-a-1;
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