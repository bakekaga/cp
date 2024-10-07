#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
	freopen("A.txt", "r", stdin);
	freopen("Aout.txt", "w", stdout);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n; cin >> n;
		double winMin = 0, winMax = MAXN;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			// at least this speed or will get there too late
			double mn = 1.0 * i / b;
			// at most this speed or will get there too early
			double mx = 1.0 * i / a;
			if (mn > winMax || mx < winMin) {
				ok = false;
			}
			else {
				winMin = max(mn, winMin);
				winMax = min(mx, winMax);
			}
		}
		cout << "Case #" << tt << ": " << (ok ? winMin : -1) << '\n';
	}
}