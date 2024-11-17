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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
	}

	vector<int> dp(n);
	int mx = 0;
	function<int(int)> dfs = [&](int cur) {
		if (dp[cur]) return dp[cur];
		for (int nbr : adj[cur]) {
			dp[nbr] = dfs(nbr);
			dp[cur] = max(dp[cur], dp[nbr] + 1);
		}
		mx = max(mx, dp[cur]);
		return dp[cur];
	};

	for (int i = 0; i < n; i++) {
		dfs(i);
	}

	cout << mx << '\n';
	return 0;
}