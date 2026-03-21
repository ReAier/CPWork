#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn=1e4+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;

int n,m;

int FastPow(int a,int x){
    int res=1;
    while(x){
        if(x&1) res*=a;
        a*=a;
        x>>=1;
    }
    return res;
}

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

struct Matrix{
    int a[maxn][maxn];
    int R,C;
    Matrix(int R=n,int C=n,int x=0):R(R),C(C){
        memset(a,0,sizeof(a));
        for(int i=1;i<=R;++i) a[i][i]=x;
    }
    int* operator[](const int &x){
        return a[x];
    }
    Matrix operator*(Matrix x){
        Matrix res(R,x.C);
        for(int i=1;i<=R;++i) for(int j=1;j<=x.C;++j) for(int k=1;k<=C;++k)
            res[i][j]=(res[i][j]+a[i][k]*x[k][j]);
        return res;
    }
    Matrix operator+(Matrix &x){
        Matrix res(R,C);
        for(int i=1;i<=R;++i) for(int j=1;j<=C;++j) res[i][j]=a[i][j]+x[i][j];
        return res;
    }
    Matrix Pow(int t){
        Matrix A=*this,res(R,C,1);
        while(t){
            if(t&1) res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
    int Gauss(){
        int r=1,c=1;
        for(;c<=n;++c){
            int cur=r;
            for(int i=r;i<=n;++i) if(fabs(a[i][c])>fabs(a[cur][c])) cur=i;
            if(fabs(a[cur][c])<eps) continue;
            swap(a[cur],a[r]);
            for(int i=n+1;i>=c;--i) a[r][i]/=a[r][c];
            for(int i=r+1;i<=n;++i) if(fabs(a[i][c])>eps) for(int j=n+1;j>=c;--j)
                a[i][j]-=a[r][j]*a[i][c];
            ++r;
        }
        if(r<=n){
            for(int i=r;i<=n;++i) if(fabs(a[i][n+1])>eps) return -1;
            return n-r+1;
        }
        for(int i=n-1;i;i--) for(int j=i+1;j<=n;++j) 
            a[i][n+1]-=a[j][n+1]*a[i][j];
        return 0;
    }
};

struct NubThe{
    int inv[maxn];
    void GetInv(){
        inv[1]=1;
        for(int i=2;i<=n;++i)
            inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    }

    int ExGcd(int a,int b,int &x,int &y){
        if(!b) return x=1,y=0,a;
        int d=ExGcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }

    vector<int>p;
    int phi[maxn];
    bool nop[maxn];
    void GetP(){
        phi[1]=1;
        for(int i=2;i<=n;++i){
            if(!nop[i]) p.push_back(i),phi[i]=i-1;
            for(int j:p){
                nop[i*j]=1;
                if(!(i%j)){
                    phi[i*j]=phi[i]*j;
                    break;
                }else phi[i*j]=phi[i]*phi[j];
            }
        }
    }
    
};

struct Combin{
    ll Catalan[maxn];
    ll fac[maxn];
    void GetCatalan(){
        Catalan[1]=1;
        for(int i=2;i<=n;++i)
            Catalan[i]=Catalan[i-1]*(4*i-2)/(i+1);
    }
    ll C(int a,int b){
        return fac[a]/(fac[b]*fac[a-b]);
    }
    void GetFac(){
        fac[0]=1;
        for(int i=1;i<=n;++i)
            fac[i]=fac[i-1]*i;
    }
};


int main() {
    return 0;
}
