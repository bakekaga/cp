#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 1;

vector<int> exhibits(MAXN);
vector<int> ord;
vector<vector<int>> adj(MAXN + 1);
bool ok = true;

void dfs(int cur, int par) {
	ord.push_back(cur);
	if (par != -1) {
		exhibits[cur]--;  // entering this node
	}
	for (int nbr : adj[cur]) {	// process all children
		if (nbr != par) {
			dfs(nbr, cur);
			ord.push_back(cur);
		}
	}
	if (exhibits[cur] < 0) {
		ok = false;
	} else if (par != -1) {	 // handle remaining exhibits, treating this as a leaf
		for (int i = 0; i < exhibits[cur]; i++) {
			ord.push_back(par);
			ord.push_back(cur);
		}
		exhibits[par] -= exhibits[cur] + 1;
		exhibits[cur] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	size_t n;
	cin >> n;
	for (size_t i = 1; i <= n; i++) {
		cin >> exhibits[i];
	}
	for (size_t i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, -1);
	if (ok && exhibits[1] == 0) {
		for (int v : ord) {
			cout << v << ' ';
		}
		cout << '\n';
	} else {
		cout << "0\n";
	}
	return 0;
}
