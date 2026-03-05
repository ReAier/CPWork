#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
using namespace std;
const int maxn=1e6+10,INF=1e9+10,mod=1e9+7;
int n,m;

string Unfold(string s){
    string NewS;
    int Num=s[1]-'0',i=2;
    if(isdigit(s[2])) Num=Num*10+s[2]-'0',i++;
    for(;i<s.size()-1;++i){
        if(s[i]=='['){
            int j=i;
            int knum=0;
            while(++j){
                if(s[j]==']'){
                    if(!knum) 
                        break;
                    else --knum;
                }
                if(s[j]=='[')++knum;
            }
            NewS+=Unfold(s.substr(i,j-i+1));
            i=j;
        }
        else NewS+=s[i];
    }
    s="";
    while(Num--)
        s+=NewS;
    return s;
}


string s;
void solve(){
    string NewS;
    for(int i=0;i<s.size();++i){
        if(s[i]=='['){
            int j=i;
            int knum=0;
            while(++j){
                if(s[j]==']'){
                    if(!knum) 
                        break;
                    else --knum;
                }
                if(s[j]=='[')++knum;
            }
            NewS+=Unfold(s.substr(i,j-i+1));
            i=j;
        }
        else NewS+=s[i];
    }
    cout<<NewS;
}

void init(){
    cin>>s;
}
int main(){
    int T=1;
    while(T--){
        init();
        solve();
    }
    AC
}