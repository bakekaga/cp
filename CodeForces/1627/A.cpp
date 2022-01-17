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
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> arr(n, vector<int>(m));
    bool good = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'B') {
                arr[i][j]++;
                good = true;
            }
        }
    }
    if (!good) cout << -1 << '\n';
    else if (arr[r - 1][c - 1]) cout << 0 << '\n';
    else {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (arr[i][c - 1]) {
                found = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (arr[r - 1][i]) {
                found = true;
                break;
            }
        }
        if (found) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}