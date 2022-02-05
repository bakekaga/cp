#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb pusv_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    stack<pair<ll, int>> s;
    for (int i = 0; i < n; i++) {
        long firstLargerThan = i;
        while (!s.empty() && v[i] < s.top().first) {
            ans = max(ans, s.top().first * (i - s.top().second));
            firstLargerThan = s.top().second;
            s.pop();
        }
        s.push({v[i], firstLargerThan});
    }
    while (!s.empty()) {
        ans = max(ans, s.top().first * (n - s.top().second));
        s.pop();
    }
    cout << ans << '\n';
    return 0;
}