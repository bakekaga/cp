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
	int n, q;
	cin >> n;
	vector<array<int, 3>> events;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int l, r, a, b;
		cin >> l >> r >> a >> b;
		events.pb({l, -1, i});
		events.pb({b, 1, i});
		ans[i] = b;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		events.pb({x, 0, i});
	}
	sort(events.rbegin(), events.rend());
	multiset<int> cur;
	vector<int> qq(q);
	for (auto &[val, type, ind] : events) {
		if (type == 0) {
			qq[ind] = val;
			if (!cur.empty() && *cur.rbegin() > qq[ind]) qq[ind] = *cur.rbegin();
		}
		else if (type == 1) {
			if (!cur.empty()) ans[ind] = *cur.rbegin();
			cur.insert(ans[ind]);
		}
		else if (type == -1) {
			cur.extract(ans[ind]);
		}
	}
	for (auto out : qq) cout << out << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}