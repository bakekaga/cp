#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int k;

vector<vector<int>> adj;
vector<bool> special;

struct Arr {
	basic_string<array<ll, 3>> arr;
	ll offset = 0;
};

vector<Arr> vals;

void dfs(int cur, int par) {
	for (int chld : adj[cur]) {
		if (chld == par) {
			continue;
		}
		dfs(chld, cur);
		vals[chld].offset++;
	}
	for (int chld : adj[cur]) {
		if (chld == par) {
			continue;
		}
		if (sz(vals[cur].arr) < sz(vals[chld].arr)) {
			swap(vals[cur], vals[chld]);
		}
		for (auto [speed, dist, id] : vals[chld].arr) {
			vals[cur].arr.pb(
				{speed, dist + vals[chld].offset - vals[cur].offset, id});
		}
	}
	if (special[cur] && sz(vals[cur].arr) > k) {
		sort(vals[cur].arr.begin(), vals[cur].arr.end(),
			 [&cur](const array<ll, 3>& a, const array<ll, 3>& b) {
				 if (a[0] * (a[1] + vals[cur].offset) ==
					 b[0] * (b[1] + vals[cur].offset)) {
					 return a[0] < b[0];
				 }
				 return a[0] * (a[1] + vals[cur].offset) <
						b[0] * (b[1] + vals[cur].offset);
			 });
		vals[cur].arr.erase(vals[cur].arr.begin() + k, vals[cur].arr.end());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m >> k;
	adj.resize(n);
	special.resize(n);
	vals.resize(n);
	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
	int p, t;
	for (int i = 0; i < m; i++) {
		cin >> p >> t;
		vals[--p].arr.push_back({t, 0, i});
	}
	int e, c;
	cin >> e >> c;
	for (int i = 0; i < c; i++) {
		cin >> x;
		special[--x] = true;
	}
	dfs(--e, -1);
	vector<ll> out(m, -1);
	for (int i = 0; i < sz(vals[e].arr); i++) {
		out[vals[e].arr[i][2]] =
			vals[e].arr[i][0] * (vals[e].arr[i][1] + vals[e].offset);
	}
	for (int i = 0; i < m; i++) {
		cout << out[i] << '\n';
	}
	return 0;
}