#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) {
			if (2 * min(a[i - 1], a[i]) > max(a[i - 1], a[i])) {
				ok = true;
			}
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
