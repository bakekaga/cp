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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n);
	vector<int> inDeg(n), outDeg(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
		inDeg[b]++;
		outDeg[a]++;
		if (a > b) swap(a, b);
	}

	int ans = 0;
	vector<bool> vis(n);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			stack<int> dfs;
			dfs.push(i);
			vector<int> cc;
			vis[i] = true;

			while (!dfs.empty()) {
				int cur = dfs.top();
				dfs.pop();
				cc.pb(cur);
				for (auto nbr : adj[cur]) {
					if (!vis[nbr]) {
						vis[nbr] = true;
						dfs.push(nbr);
					}
				}
			}

			if (sz(cc) == k) {
				bool works = true;
				for (int v : cc) {
					if (inDeg[v] != k - 1 || outDeg[v] != k - 1) {
						works = false;
						break;
					}
				}
				if (works) ans++;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}