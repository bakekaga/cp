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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k, n; cin >> k >> n;
	vector<ll> a(n);
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	sort(a.begin(), a.end());
	ll l = 1, r = tot / k;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += min(a[i], mid);
		}
		// construction is distribute [min(a[i], mid)] of
		// each group across all [mid] councils, guaranteed no
		// council uses the same group twice since <= [mid]
		// members of each group are distributed across mid
		// councils
		if (sum < mid * k) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << r << '\n';
	return 0;
}