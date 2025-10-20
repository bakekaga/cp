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
	cin >> n;
	if (n == 2) {
		cout << "-1\n";
	} else if (n == 3) {
		cout << "1 3\n2 3\n";
	} else if (n == 4) {
		cout << "1 2\n3 1\n4 1\n";
	} else if (n == 5) {
		cout << "2 1\n2 3\n2 4\n4 5\n";
	} else {
		cout << "1 2\n2 3\n3 4\n1 " << n << "\n";
		for (int i = 5; i < n; i++) {
			cout << "2 " << i << "\n";
		}
	}
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