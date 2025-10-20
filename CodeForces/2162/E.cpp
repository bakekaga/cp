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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<bool> used(n + 1);
	vector<int> avail;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (!used[a[i]]) {
			avail.push_back(a[i]);
		}
		used[a[i]] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			avail.push_back(i);
		}
	}
	reverse(avail.begin(), avail.end());
	for (int i = 0; i < k; i++) {
		cout << avail[i % 3] << ' ';
	}
	cout << '\n';
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