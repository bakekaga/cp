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
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[--a].pb(--b);
	}
 
	vector<int> vis(n), ord;
	function<bool(int)> dfs = [&](int cur) {
		vis[cur]++;
		for (int i : adj[cur]) {
			if (vis[i] == 1) {
				return true;
			}
			else if (!vis[i]) {
				if (dfs(i))
					return true;
			}
		}
		vis[cur]++;
		ord.push_back(cur);
		return false;
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (dfs(i)) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	reverse(ord.begin(), ord.end());
	for (int node : ord) {
		cout << node + 1 << ' ';
	}
	return 0;
}