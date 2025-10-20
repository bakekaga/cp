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
	unsigned int a, b;
	cin >> a >> b;
	if (countl_zero(a) > countl_zero(b)) {
		cout << "-1\n";
		return;
	}
	cout << "2\n";
	int cur = 0;
	for (int i = 0; i < (32 - countl_zero(b)); i++) {
		cur |= (a & (1 << i)) ^ (b & (1 << i));
	}
	cout << cur << " ";
	cur = 0;
	for (int i = (32 - countl_zero(b)); i < (32 - countl_zero(a)); i++) {
		cur |= (a & (1 << i)) ^ (b & (1 << i));
	}
	cout << cur << '\n';
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