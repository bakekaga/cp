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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> colors(n);
	for (int i = 0; i < n; i++) {
		cin >> colors[i];
		colors[i]--;
	}

	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}

	vector<set<int>> subtrees(n);
	vector<int> out(n);
	function<void(int, int)> dfs = [&](int cur, int par) -> void {
		for (int chld : adj[cur]) {
			if (chld != par) {
				dfs(chld, cur);
				// merge from small to large
				if (subtrees[cur].size() < subtrees[chld].size()) {
					swap(subtrees[cur], subtrees[chld]);
				}
				for (int val : subtrees[chld]) {
					subtrees[cur].insert(val);
				}	
			}
		}
		// add result from color of current node
		subtrees[cur].insert(colors[cur]);
		// immediately set value for this node to avoid O(n) recalculation later
		out[cur] = subtrees[cur].size();
	};

	dfs(0, -1);
	for (auto i : out) {
		cout << i << ' ';
	}

	return 0;
}