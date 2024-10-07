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

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".txt").c_str(), "r", stdin);
        freopen((prob + "out.txt").c_str(), "w", stdout);
    }
}

int main() {
    setIO("A");
	cout << fixed;
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
		cin >> n;
		vector<ll> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		cout << "Case #" << tt << ": ";
		if (n == 5) {
			cout << max((x[n - 1] + x[n - 2]) / 2.0 - (x[0] + x[2]) / 2.0, (x[n - 1] + x[n - 3]) / 2.0 - (x[0] + x[1]) / 2.0) << '\n';
		}
		else cout << (x[n - 1] - x[0] + x[n - 2] - x[1]) / 2.0 << '\n';
    }
}