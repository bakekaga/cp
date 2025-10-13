#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
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
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int len = static_cast<int>(sqrt(static_cast<double>(n))) + 1;
	vector<int> rmq(len);
	for (int i = 0; i < n; i++) {
		rmq[i / len] = max(rmq[i / len], h[i]);
	}

	int tot = 0;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (a >= b - 1) {
			tot++;
			continue;
		}
		int i = a, j = b - 2;
		int ans = 0;
		while (i <= j) {
			if (i % len == 0 && i + len < j) {
				ans = max(ans, rmq[i / len]);
				i += len;
			}
			else {
				ans = max(ans, h[i]);
				i++;
			}
		}
		tot += (ans <= h[a - 1]);
	}
	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
