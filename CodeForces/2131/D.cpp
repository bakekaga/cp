#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
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
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	set<int> leaves;
	for (int i = 0; i < n; i++) {
		if (sz(adj[i]) == 1) {
			leaves.insert(i);
		}
	}

	map<int, int> leaf_nbr_freq;
	for (int leaf : leaves) {
		leaf_nbr_freq[adj[leaf][0]]++;
	}
	int mx = 0;
	for (auto &[root, cnt] : leaf_nbr_freq) {
		mx = max(mx, cnt + (int) (leaves.count(root)));
	}
	cout << sz(leaves) - mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
