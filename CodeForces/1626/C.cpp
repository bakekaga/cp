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
    int n; cin >> n;
    vector<ll> k(n), h(n);
    vector<pair<ll, ll>> events(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        events[i] = mp(k[i] - h[i], k[i]);
    }
    sort(events.begin(), events.end());
    ll cnt = 0, curl = events[0].first, curr = events[0].second;
    for (int i = 1; i < n; i++) {
        if (events[i].first >= curr) {
            cnt+= (curr - curl) * (curr - curl + 1) / 2;
            curr = events[i].second;
            curl = events[i].first;
        }
        else {
            curr = max(curr, events[i].second);
        }
    }
    cnt+= (curr - curl) * (curr - curl + 1) / 2;
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}