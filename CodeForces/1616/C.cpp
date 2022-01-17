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
    int n, out = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n < 3) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double diff = ((double) a[j] - a[i]) / (j - i);
            int cnt = 0;
            double cur = a[i] - diff * i;
            for (int k = 0; k < n; k++) {
                if (fabs(a[k] - cur) < EPS) cnt++;
                cur+= diff;
            }
            out = max(out, cnt);
        }
    }
    cout << n - out << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}