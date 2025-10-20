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
	cout << "2 1 " << n << endl;
	ll tot;
	cin >> tot;
	ll range_size = tot - (n + 1LL) * n / 2;
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		ll cur_tot;
		cout << "2 " << lo << " " << mid << endl;
		cin >> cur_tot;
		ll cur_orig;
		cout << "1 " << lo << " " << mid << endl;
		cin >> cur_orig;
		if (cur_tot - cur_orig == 0) {
			lo = mid + 1;
		} else if (cur_tot - cur_orig == range_size) {
			hi = mid - 1;
		} else {
			cout << "! " << mid - (cur_tot - cur_orig) + 1 << " " << mid + range_size - (cur_tot - cur_orig) << endl;
			return;
		}
	}
	cout << "! " << lo << " " << lo + range_size - 1 << endl;
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