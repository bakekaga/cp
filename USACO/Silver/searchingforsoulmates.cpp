#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

void solve() {
    ll a, b; cin >> a >> b;
    vector<pair<ll, ll>> asteps;
    vector<pair<ll, ll>> bsteps;
    for (ll cnt = 0, cura = a; cura < b;) {
        asteps.pb({cura, cnt});
        cnt++;
        cura*= 2;
    }
    for (ll cnt = 0, cura = a; cura > 0; cnt++) {
        asteps.pb({cura, cnt});
        if ((cura % 2) == 1 && cura != 1) {
            cura = (cura + 1) / 2;
            cnt++;
        }
        else cura/= 2;
    }
    for (ll cnt = 0, curb = b; curb < a;) {
        bsteps.pb({curb, cnt});
        cnt++;
        curb*= 2;
    }
    for (ll cnt = 0, curb = b; curb > 0; cnt++) {
        bsteps.pb({curb, cnt});
        if ((curb % 2) == 1 && curb != 1) {
            curb = (curb - 1) / 2;
            cnt++;
        }
        else curb/= 2;
    }

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < asteps.size(); i++) {
        for (int j = 0; j < bsteps.size(); j++) {
            if (asteps[i].first <= bsteps[j].first) ans = min(ans, bsteps[j].second + asteps[i].second + bsteps[j].first - asteps[i].first);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}