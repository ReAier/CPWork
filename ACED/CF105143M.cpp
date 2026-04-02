#include<bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i = 1; i <= n; ++ i)
using ll = long long;
const ll inf = 1e18;
const int N = 1e6 + 10, P = 1e9 + 7;
ll a[N],a0[N];
map<ll,ll> mp0, mp1;
ll n,m;

vector<ll> FindM(ll x) {
    if (mp1[x]) return  {x};
    ll x1 = x / 2, x2 = x1 + 1;
    if (x2 & 1) swap(x1, x2);
    if (mp0[x2]) {
        mp0[x2]--;
        auto v = FindM(x1);
        mp0[x2]++;
        if (v.size()) {
            v.push_back(x2);
            return v;
        }
    }
    return {};
}

vector<ll> ans;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] & 1)
            mp1[a[i]]++;
        else
            mp0[a[i]]++,a0[++m]=a[i];
    }
    sort(a0+1,a0+1+m,[](ll x,ll y){return x>y;});
    for(int i=1;i<=m;++i){
        ll u = a0[i];
        while(mp0[u]){
            mp0[u]--;
            auto v = FindM(u + 1);
            if (v.size())
                ans.push_back(2 * u + 1);
            else {
                v = FindM(u - 1);
                if (v.size())
                    ans.push_back(2 * u - 1);
                else
                    ans.push_back(u);
            }
            for (ll k : v)
                if (k & 1)
                    mp1[k]--;
                else
                    mp0[k]--;
        }
    }
    for (auto [u, w] : mp1)
        for (int i = 1; i <= w; ++i)
            ans.push_back(u);
    sort(ans.begin(), ans.end(), [](ll x, ll y) { return x > y; });
    cout << ans.size() << "\n";
    for (ll u : ans)
        cout << u << " ";
}

int main() {
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}
