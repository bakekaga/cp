#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n + 1);
	vector<ll> psums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psums[i] = a[i];
		if (i) {
			psums[i] += psums[i - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		ll d1, m1, d2, m2;
		cin >> d1 >> m1 >> d2 >> m2;
		ll tot = 0;
		if (m2 == m1) {
			tot = d2 - d1 + 1;
		} else {
			tot = a[m1] - d1 + 1;
			tot += psums[m2 - 1] - psums[m1];
			tot += d2;
		}
		if (tot <= 0) {
			tot += psums[n];
		}
		cout << tot << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
