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
 	queue<int> q;
	vector<int> ord, indegree(n);
	for (int i = 0; i < n; i++) {
		for (int to : adj[i]) {
			indegree[to]++;
		}
	}
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
	
	if (sz(ord) < n) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		for (int node : ord) {
			cout << node + 1 << ' ';
		}
	}
	return 0;
}