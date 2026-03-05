#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#ifndef ONLINE_JUDGE
#define OPEN_FILE
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
ull n,m;
mt19937_64 mt(time(nullptr));
const ull Key[5]={13612236352513982139ull,141386042297581511ull,13457593982110287426ull,8319193235722508964ull,10640675335139574128ull},KeyN=1488024513935251242;
set<ull>Mp[5];
const string Password="bl2018618",FilePath="C:/temp/Key";

ull tmpK[maxn];
void AutoSave(){
    ofstream OutFile(FilePath,ios::binary);
    n=Mp[0].size();
    OutFile<<(n^KeyN)<<" ";
    for(int i=0;i<5;++i){
        int idx=0;
        for(ull k:Mp[i])
            tmpK[++idx]=k;
        shuffle(tmpK+1,tmpK+n+1,mt);
        for(int j=1;j<=n;++j)
            OutFile<<tmpK[j]<<" ";
    }
    int T=mt()%15;
    while(T--) for(int i=0;i<5;++i)
        OutFile<<mt()<<" ";
}

ull CreatKey(){
    while(1){
        ull k0=mt(),flg=0;
        for(int i=0;i<5;++i){
            ull k=k0^Key[i];
            if(Mp[i].count(k))
                flg=1;
        }
        if(!flg) {
            for(int i=0;i<5;++i)
                Mp[i].insert(k0^Key[i]);
            AutoSave();
            return k0;
        }
    }
}
bool DeleteKey(ull k){
    bool flg=1;
    for(int i=0;i<5;++i)
        if(!Mp[i].count(k^Key[i]))
            flg=0;
    if(flg) {
        for(int i=0;i<5;++i)
            Mp[i].erase(k^Key[i]);
    }
    AutoSave();
    return flg;
}
string GetPassword(){
    string pass;
    while(1){
        char ch=_getch();
        if (ch == '\r') {
            cout << endl;
            return pass;
        } else if (ch == '\b') { 
            if (!pass.empty()) {
                pass.pop_back();
                cout << "\b \b";
            }
        } else {
            pass.push_back(ch);
            cout << '*'; 
        }
    }
}
bool EnterPassword(){
    string Pass=GetPassword();
    if(Pass.length()!=Password.length()) return 0;
    for(int i=0;i<Password.length();++i)
        if(Pass[i]!=Password[i])
            return 0;
    return 1;
}

void solve(){
    ull opt,k;
    while(1){
        cout<<"1:创建\n2:核销\n";
        cin>>opt;
        if(opt==1){
            cout<<"输入密码以创建:\n";
            if(EnterPassword()){
                cout<<"输入创建数量:\n";
                cin>>opt;
                while(opt--){
                    k=CreatKey();
                    cout<<"编号: "<<k<<'\n';
                }
            }else cout<<"密码错误\n";
        }else if(opt==2){
            cout<<"输入核销数量:\n";
            cin>>opt;
            while(opt--){
                cout<<"核销编号:\n";
                cin>>k;
                if(DeleteKey(k)) 
                    cout<<"核销成功!\n";
                else cout<<"错误的编号\n";
            }
        }
    }
}
void init(){
    ifstream InFile(FilePath,ios::binary);
    InFile>>n;
    if(!n) return;
    n^=KeyN;
    for(int i=0;i<5;++i){
        ull k;
        for(int j=1;j<=n;++j)
            InFile>>k,Mp[i].insert(k);
    }
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    init();
    solve();
    return 0;
}