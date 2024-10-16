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
	vector<vector<int>> adj(n), revAdj(n);
	vector<int> indegree(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		revAdj[b].pb(a);
		indegree[b]++;
	}
	queue<int> q;
	vector<int> ord;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ord.pb(cur);
		for (int to : adj[cur]) {
			if (--indegree[to] == 0) {
				q.push(to);
			}
		}
	}
	vector<int> dp(n, -INF), par(n, -1);
	dp[0] = 1;
	for (int cur : ord) {
		for (int prev : revAdj[cur]) {
			if (dp[prev] + 1 > dp[cur]) {
				dp[cur] = dp[prev] + 1;
				par[cur] = prev;
			}
		}
	}
	if (dp[n - 1] < 0) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		vector<int> out;
		for (int v = n - 1; v != -1; v = par[v]) {
			out.pb(v);
		}
		cout << out.size() << '\n';
		for (int i = out.size() - 1; i >= 0; i--) {
			cout << out[i] + 1 << ' ';
		}
	}
	return 0;
}