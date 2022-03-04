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

vector<array<int, 2>> adj[MAXN], dfsTree[MAXN];
int backEdgesUp[2 * MAXN], backEdgesDown[2 * MAXN], vis[MAXN], dp[MAXN];
array<int, 3> edges[2 * MAXN];

void dfs(int cur, int ord) {
	vis[cur] = ord;
	for (auto &x : adj[cur]) {
		if (!vis[x[0]]) {
			dfsTree[cur].pb(x);
			dfs(x[0], ord + 1);
		}
		else if (vis[x[0]] < vis[cur] - 1) {
			backEdgesUp[cur]++;
			backEdgesDown[x[0]]++;
		}
	}
}

void dfsAns(int cur) {
	for (auto &x : dfsTree[cur]) {
		if (!dp[x[0]]) edges[x[1]][2]++;
		dfsAns(x[0]);
	}
}

int solve(int cur) {
	if (dp[cur] != -1) return dp[cur];
	dp[cur] = backEdgesUp[cur] - backEdgesDown[cur];
	for (auto &x : dfsTree[cur]) {
		dp[cur]+= solve(x[0]);
	}
	return dp[cur];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb({b, i});
		adj[b].pb({a, i});
		edges[i] = {a, b};
	}
	memset(dp, -1, sizeof dp);
	dfs(1, 1);
	solve(1);
	dfsAns(1);

	vector<array<int, 2>> ans;
	for (int i = 0; i < m; i++) {
		if (edges[i][2]) ans.pb({edges[i][0], edges[i][1]});
	}
	cout << sz(ans) << '\n';
	for (auto &x : ans) cout << x[0] << ' ' << x[1] << '\n';
	
	return 0;
}