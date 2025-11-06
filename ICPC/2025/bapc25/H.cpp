#include <bits/stdc++.h>
using namespace std;

#define pb push_back
constexpr int INF = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}

	vector<int> dist(n, INF);
	vector<int> prev(n, INF);
	int ans = INF;
	array<int, 2> best_backtrack = {0, 0};
	queue<array<int, 3>> bfs;
	bfs.push({0, 1, -1});
	dist[0] = 1;
	while (!bfs.empty()) {
		auto [cur, dist_elapsed, par] = bfs.front();
		prev[cur] = par;
		bfs.pop();
		for (int nbr : adj[cur]) {
			if (nbr == par) {
				continue;
			} else if (dist[nbr] != INF) {
				if (ans > dist[nbr] + dist_elapsed) {
					ans = dist[nbr] + dist_elapsed;
					best_backtrack = {cur, nbr};
				}
			} else {
				dist[nbr] = dist_elapsed + 1;
				bfs.push({nbr, dist_elapsed + 1, cur});
			}
		}
	}
	if (ans < INF) {
		cout << ans << '\n';
		vector<int> ord;
		int cur = best_backtrack[0];
		while (cur != -1) {
			ord.pb(cur);
			cur = prev[cur];
		}
		reverse(ord.begin(), ord.end());
		cur = best_backtrack[1];
		while (cur != -1) {
			ord.pb(cur);
			cur = prev[cur];
		}
		for (int v : ord) {
			cout << v + 1 << ' ';
		}
		cout << '\n';
	} else {
		cout << "impossible\n";
	}
}
