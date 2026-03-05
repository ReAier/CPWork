#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
// #define OPEN_FILE
// #define OPEN_TIME
#endif
#define AC return 0;
#define lowbit(x) (x&(-x))
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e2+10,INF=0x3f3f3f3f,mod=1e9+7;
const double eps=1e-8;
int n;
int D,L;
double com_min,Alpha,Beta,K_max;
double NowCash=1e5;

int T;
struct StockMarket{
    struct Stock {
        string Date,Code;
        double Open,High,Low,Close,PctChg,Amplitude,Turnover;
        ll Volume,Amount,Change;
    };
    int NowK;
    double NowS[maxn],LasS[maxn];
    vector<Stock>st[maxn];
    Stock GetStock(){
        Stock s;
        string line;
        getline(cin, line);
        while (line.size() == 0) getline(cin, line);
        for (char &c : line)
            if (c == ',') c = ' ';
        stringstream ss(line);
        ss >> s.Date >> s.Code
           >> s.Open >> s.High >> s.Low >> s.Close
           >> s.Volume >> s.Amount
           >> s.Amplitude >> s.PctChg
           >> s.Change >> s.Turnover;
        return s;
    }
    void Buy(int Code,int val){
        val*=L;
        if(NowK==K_max||!val) return;
        cout<<"BUY "<<st[Code][0].Code<<" "<<val<<'\n';
        LasS[Code]+=val;
        ++NowK;
    }
    void Sell(int Code,int val){
        val*=L;
        if(NowK==K_max||NowS[Code]<val||!val) return;
        cout<<"SELL "<<st[Code][0].Code<<" "<<val<<'\n';
        LasS[Code]-=val;
        ++NowK;
    }
    void GetDay(){
        NowK=0;
        for(int i=1;i<=n;++i)
            st[i].push_back(GetStock());
        for(int i=1;i<=n;++i){
            double Open=st[i].back().Open;
            if(Open>0) {
                if(LasS[i]>0){
                    double DCash=LasS[i]*Open;
                   DCash+=max(com_min,DCash*Alpha);
                   if(NowCash-DCash>=0) 
                        NowS[i]+=LasS[i],NowCash-=DCash;
                }else if(LasS[i]<0){
                    double DCash=-LasS[i]*Open;
                    DCash-=max(com_min,DCash*Alpha)+DCash*Beta;
                    if(NowS[i]>=-LasS[i]) 
                        NowS[i]+=LasS[i],NowCash+=DCash;
                }
            }
            LasS[i]=0;
        }
    }
}s;
struct Decision {
    // ===== 参数=====
    static constexpr int K = 20;
    static constexpr double ThetaBuy  = 0.02;
    static constexpr double ThetaSell = -0.02;

    double SumPct[maxn];
    vector<StockMarket::Stock>* st;
    pair<double,int>a[maxn];
    void Make() {
        st = s.st;

        for (int i = 1; i <= n; ++i) {
            double add = st[i][T].PctChg;
            double sub = (T >= K ? st[i][T - K].PctChg : 0.0);
            SumPct[i] += add - sub;
            a[i].first=SumPct[i],a[i].second=i;
        }

        // sort(a+1,a+1+n);

        for (int i = 1; i <= n; ++i) {
            int len = min(K, T + 1),id=a[i].second;
            double Theta = a[i].first / len;

            if (Theta < ThetaSell && s.NowS[id] > 0) {
                s.Sell(id, s.NowS[id] / L);
                continue;
            }

            if (Theta > ThetaBuy) {
                double open = st[id][T].Open;
                if (open <= 0) continue;

                double useCash = NowCash * 0.20;
                s.Buy(id, useCash / open / L);
            }
        }
    }
}d;



void solve(){
    for(T=0;T<D;++T){
        d.Make();
        cout<<"DONE"<<endl;
        s.GetDay();
    }
    cout<<"DONE"<<endl;
}
void init(){
    string S;
    cin>>S>>n>>D>>NowCash>>L>>Alpha>>com_min>>Beta>>K_max;
    s.GetDay();
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