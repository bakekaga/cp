#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
vector<int> grafo[maxn];

void solve() {
	int n;
	cin >> n;
	vector<int> deg(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int v;
			cin >> v;
			grafo[v].push_back(i);
			deg[i]++;
		}
	}
	queue<int> fila;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			fila.push(i);
			dp[i] = 1;
		}
	}
	int ans = 0;
	while (!fila.empty()) {
		int u = fila.front();
		fila.pop();
		for (int v : grafo[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			if (dp[v] == n) {
				ans = 1;
			}
			deg[v]--;
			if (deg[v] == 0) {
				fila.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		// cout << dp[i] << " ";
		grafo[i].clear();
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}