#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=500+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n,m;


struct BigInt {
    vector<int> s;
    BigInt(string num = "0") {
        for (int i = num.size() - 1; i >= 0; i--) s.push_back(num[i] - '0');
        trim();
    }
    BigInt(ll num){
        while(num){
            s.push_back(num%10);
            num/=10;
        }
    }
    string ToStr(){
        string st;
        for(int i:s) st.push_back(i+'0');
        reverse(st.begin(), st.end());
        return st;
    }
    void clear(){
        s.clear();
    }
    size_t size(){
        return s.size();
    }
    ll ToLL(){
        ll ans=0;
        for(int i=s.size()-1;i>=0;--i) ans=ans*10+s[i];
        return ans;
    }
    void trim() {
        while (s.size() > 1 && s.back() == 0) s.pop_back();
    }
    void print() {
        for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
    }
    vector<int>::reference operator[](int i){
        return s[i];
    }
    BigInt operator+(BigInt &A){
        BigInt C;
        C.clear();
        int t = 0;
        for (int i = 0; i < (int)max(A.size(), size()); i++) {
            if (i < A.size()) t += A[i];
            if (i < size()) t += s[i];
            C.s.push_back(t % 10);
            t /= 10;
        }
        if (t) C.s.push_back(t);
        return C;
    }
    bool operator<(BigInt &A){
        if (A.size() != size()) return A.size() > size();
        for (int i = A.size() - 1; i >= 0; i--)
            if (A[i] != s[i]) return A[i] > s[i];
        return true;
    }
    bool operator>(BigInt &A){
        if (A.size() != size()) return A.size() < size();
        for (int i = A.size() - 1; i >= 0; i--)
            if (A[i] != s[i]) return A[i] < s[i];
        return 0;    
    }
    bool operator==(BigInt &A){
        if (A.size() != size()) return 0;
        for(int i=A.size()-1;i>=0;--i) if(A[i]!=s[i]) return 0;
        return 1;
    }
    bool operator!=(BigInt &A){
        if (A.size() != size()) return 1;
        for(int i=A.size()-1;i>=0;--i) if(A[i]!=s[i]) return 1;
        return 0;
    }
    BigInt operator-(BigInt &B){
        BigInt C;
        C.clear();
        int t = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            t = s[i] - t;
            if (i < B.size()) t -= B[i];
            C.s.push_back((t + 10) % 10);
            t = (t < 0);
        }
        C.trim();
        return C;
    }
    BigInt operator*(BigInt &A){
        BigInt C;
        C.s.assign(A.size() + size(), 0);
        for (int i = 0; i < (int)A.size(); i++) {
            int t = 0;
            for (int j = 0; j < (int)size() || t; j++) {
                ll cur = C[i + j] + 1ll * A[i] * (j < size() ? s[j] : 0) + t;
                C[i + j] = cur % 10;
                t = cur / 10;
            }
        }
        C.trim();
        return C;
    }
    BigInt operator*(ll b){
        BigInt C;
        C.clear();
        ll t = 0;
        for (int i = 0; i < (int)size() || t; i++) {
            if (i < size()) t += 1ll * s[i] * b;
            C.s.push_back(t % 10);
            t /= 10;
        }
        C.trim();
        return C;
    }
    BigInt operator/(ll b){
        BigInt C;
        C.clear();
        ll r = 0;
        for (int i = size() - 1; i >= 0; i--) {
            r = r * 10 + s[i];
            C.s.push_back(r / b);
            r %= b;
        }
        reverse(C.s.begin(), C.s.end());
        C.trim();
        return C;
    }
    ll operator%(ll b){
        ll r = 0;
        for (int i = size() - 1; i >= 0; i--) {
            r = r * 10 + s[i];
            r %= b;
        }
        return r;
    }
};

BigInt C[maxn];

void solve(){
    C[1]=1;
    for(int i=2;i<=n;++i) C[i]=C[i-1]*(4*i-2),C[i]=C[i]/(i+1);
    C[n].print();
}

void init(){
    cin>>n;
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