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
	int n;
	cin >> n;
	vector<int> a(n), b, c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mx = *max_element(a.begin(), a.end());
	for (auto x : a) {
		if (x == mx) {
			c.pb(x);
		}
		else {
			b.pb(x);
		}
	}
	if (!sz(b)) {
		cout << -1 << '\n';
	}
	else {
		cout << sz(b) << ' ' << sz(c) << '\n';
		for (auto x : b) cout << x << ' ';
		cout << '\n';
		for (auto x : c) cout << x << ' ';
		cout << '\n';
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