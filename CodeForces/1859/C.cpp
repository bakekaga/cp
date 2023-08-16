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
	ll tot = n * (n + 1LL) * (2 * n + 1) / 6;
	ll mx = tot - n * n;
	for (ll i = n - 1; i >= 1; i--) {
		ll temp = tot, tempmx = (i - 1) * (i - 1);
		for (ll j = n; j >= i; j--) {
			temp += j * (i - 2 * j + n);
			tempmx = max(tempmx, j * (i - j + n));
		}
		temp -= tempmx;
		mx = max(mx, temp);
	}
	cout << mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}