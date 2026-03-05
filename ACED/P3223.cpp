#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;

struct BigInt {
    vector<int> s;
    BigInt(string num = "0") {
        for (int i = num.size() - 1; i >= 0; i--) s.push_back(num[i] - '0');
        trim();
    }
    BigInt(long long num){
        while(num){
            s.push_back(num%10);
            num/=10;
        }
    }
    void trim() {
        while (s.size() > 1 && s.back() == 0) s.pop_back();
    }
    void print() const {
        for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
    }
    BigInt operator+(const BigInt &A)const{
        BigInt C;
        C.s.clear();
        int t = 0;
        for (int i = 0; i < (int)max(A.s.size(), s.size()); i++) {
            if (i < A.s.size()) t += A.s[i];
            if (i < s.size()) t += s[i];
            C.s.push_back(t % 10);
            t /= 10;
        }
        if (t) C.s.push_back(t);
        return C;
    }
    BigInt operator-(const BigInt &B)const{
        BigInt C;
        C.s.clear();
        int t = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            t = s[i] - t;
            if (i < B.s.size()) t -= B.s[i];
            C.s.push_back((t + 10) % 10);
            t = (t < 0);
        }
        C.trim();
        return C;
    }
    BigInt operator*(const BigInt &A)const{
        BigInt C;
        C.s.assign(A.s.size() + s.size(), 0);
        for (int i = 0; i < (int)A.s.size(); i++) {
            int t = 0;
            for (int j = 0; j < (int)s.size() || t; j++) {
                long long cur = C.s[i + j] + 1ll * A.s[i] * (j < s.size() ? s[j] : 0) + t;
                C.s[i + j] = cur % 10;
                t = cur / 10;
            }
        }
        C.trim();
        return C;
    }
    BigInt operator*(const long long &b)const{
        BigInt C;
        C.s.clear();
        long long t = 0;
        for (int i = 0; i < (int)s.size() || t; i++) {
            if (i < s.size()) t += 1ll * s[i] * b;
            C.s.push_back(t % 10);
            t /= 10;
        }
        C.trim();
        return C;
    }
};

BigInt N=1,M1=1,M2=1;

void solve(){
    for(int i=1;i<=n+1;++i) N=N*i;
    M1=N*(n+2);
    for(int i=1;i<=m;++i) M1=M1*(n+4-i);

    M2=N*2;
    for(int i=1;i<=m;++i) M2=M2*(n+3-i);
    (M1-M2).print();
}

void init(){
    cin>>n>>m;
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