#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
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
    bool operator<(const BigInt &A)const{
        if (A.s.size() != s.size()) return A.s.size() > s.size();
        for (int i = A.s.size() - 1; i >= 0; i--)
            if (A.s[i] != s[i]) return A.s[i] > s[i];
        return true;    
    }
    bool operator>(const BigInt &A)const{
        if (A.s.size() != s.size()) return A.s.size() < s.size();
        for (int i = A.s.size() - 1; i >= 0; i--)
            if (A.s[i] != s[i]) return A.s[i] < s[i];
        return 0;    
    }
    bool operator==(const BigInt &A)const{
        if (A.s.size() != s.size()) return 0;
        for(int i=A.s.size()-1;i>=0;--i) if(A.s[i]!=s[i]) return 0;
        return 1;
    }
    bool operator!=(const BigInt &A)const{
        if (A.s.size() != s.size()) return 1;
        for(int i=A.s.size()-1;i>=0;--i) if(A.s[i]!=s[i]) return 1;
        return 0;
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
    BigInt operator/(const long long &b)const{
        BigInt C;
        C.s.clear();
        long long r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            r = r * 10 + s[i];
            C.s.push_back(r / b);
            r %= b;
        }
        reverse(C.s.begin(), C.s.end());
        C.trim();
        return C;
    }
    long long operator%(const long long &b)const{
        long long r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            r = r * 10 + s[i];
            r %= b;
        }
        return r;
    }
};

struct Node{
    int a,b;
}a[2000];
bool cmp(Node a,Node b){
    return a.a*a.b<b.a*b.b;
}

void solve(){
    sort(a+1,a+1+n,cmp);
    BigInt ans,s(a[0].a);
    for(int i=1;i<=n;++i){
        if(s/a[i].b>ans)
            ans=s/a[i].b;
        s=s*a[i].a;
    }
    ans.print();
}

void init(){
    cin>>n;
    for(int i=0;i<=n;++i) cin>>a[i].a>>a[i].b;
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}