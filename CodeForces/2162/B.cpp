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
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> removed, remaining;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				removed.push_back(j);
			} else {
				remaining.push_back(j);
			}
		}
		bool ok = true;
		for (int j = 1; j < removed.size(); j++) {
			if (s[removed[j]] == '0' && s[removed[j - 1]] == '1') {
				ok = false;
				break;
			}
		}
		if (!ok) {
			continue;
		}
		for (int j = 0; j < remaining.size() / 2; j++) {
			if (s[remaining[j]] != s[remaining[remaining.size() - 1 - j]]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << removed.size() << '\n';
			for (int j : removed) {
				cout << j + 1 << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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