#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;

void solve() {
	int n; cin >> n;
	vector<map<int, int>> lines(4);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		lines[0][x]++;
		lines[1][y]++;
		lines[2][x + y]++;
		lines[3][y - x]++;
	}
	ll tot = 0;
	for (auto rot : lines) {
		for (auto &[line, cnt] : rot) {
			tot+= 1LL * cnt * (cnt - 1);
		}
	}
	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
