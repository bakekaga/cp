#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-6;

void solve() {
    int n, m;
    cin >> n >> m;
    int cdx[4] = {0, n - 1, 0, n - 1};
    int cdy[4] = {m - 1, 0, 0, m - 1};
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int k = 0; k < 4; k++) {
                cur = max(cur, abs(cdx[k] - i) + abs(cdy[k] - j));
            }
            v.pb(cur);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * m; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}