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

vector<int> adj[MAXN];
int vis[MAXN], endV;
vector<int> res;
bool backtracking = false;

void dfs(int cur, int dist = 0, int prev = -1) {
	vis[cur] = dist;
	dist++;
	for (int x : adj[cur]) {
		if (x == prev) continue;
		if (vis[x] == -1) dfs(x, dist, cur);
		else {
			res.pb(x);
			endV = x;
			backtracking = true;
		}
		if (backtracking) {
			res.pb(cur);
			if (cur == endV) backtracking = false;
			return;
		}
		if (!backtracking && sz(res)) return;
	}
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(vis, -1, sizeof vis);
	for (int i = 1; i <= n; i++) {
		if (vis[i] == -1) dfs(i);
		if (sz(res)) break;
	}

	if (!sz(res)) cout << "IMPOSSIBLE\n";
	else {
		cout << sz(res) << '\n';
		for (int x : res) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}