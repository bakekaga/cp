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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	
	int n; cin >> n;
	vector<ll> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int par;
		cin >> par;
		adj[--par].pb(i);
	}

	vector<ordered_set> subtrees(n);
	vector<int> out(n);

	function<void(int)> dfs = [&](int cur) {
		for (int chld : adj[cur]) {
			dfs(chld);
			if (subtrees[chld].size() > subtrees[cur].size()) {
				subtrees[cur].swap(subtrees[chld]);
			}
			for (auto val : subtrees[chld]) {
				subtrees[cur].insert(val);
			}
		}
		subtrees[cur].insert(p[cur]);
		out[cur] = subtrees[cur].size() - subtrees[cur].order_of_key(p[cur]) - 1;
	};

	dfs(0);

	for (int i : out) {
		cout << i << '\n';
	}
	return 0;
}