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
	int n; cin >> n;
	map<ll, vector<int>> a;
	for (int i = 0; i < n; i++) {
		ll val;
		cin >> val;
		a[val].pb((i + 1) % n);
	}
	int cur = 1;
	ll tot = 0;
	for (auto &[key, val] : a) {
		sort(val.begin(), val.end());
		int nextIdx = lower_bound(val.begin(), val.end(), cur) - val.begin();
		nextIdx %= sz(val);
		for (int i = 0; i < sz(val); i++) {
			ll toAdd = (val[nextIdx] - cur) % n;
			if (toAdd < 0) {
				toAdd += n;
			}
			tot += toAdd;
			cur = val[nextIdx];
			nextIdx = (1 + nextIdx) % sz(val);
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