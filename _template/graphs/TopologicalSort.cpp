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

// TOPOLOGICAL SORT WITH CYCLE DETECTION IN O(n + m)

int cycle_end, cycle_start;

bool dfs(int cur, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ord, vector<int> &parent) {
	vis[cur]++;
	for (int i : adj[cur]) {
		if (vis[i] == 1) {
			cycle_end = cur;
			cycle_start = i;
			return true;
		}
		else if (!vis[i]) {
			parent[i] = cur;
			if (dfs(i, adj, vis, ord, parent))
				return true;
		}
	}
	vis[cur]++;
	ord.push_back(cur);
	return false;
}

// DFS
vector<int> topoSort(vector<vector<int>> &adj) {
	vector<int> ord, vis(adj.size()), parent(adj.size());
	for (int i = 0; i < adj.size(); i++) {
		if (!vis[i]) {
			if (dfs(i, adj, vis, ord, parent)) {
				vector<int> cycle;
				cycle.push_back(cycle_start);
				for (int v = cycle_end; v != cycle_start; v = parent[v])
					cycle.push_back(v);
				cycle.push_back(cycle_start);
				reverse(cycle.begin(), cycle.end());
				return cycle;
			}
		}
	}
	reverse(ord.begin(), ord.end());
	return ord;
}

// BFS (Kahn's Algorithm)
vector<int> topoSort(vector<vector<int>> &adj) {
	queue<int> q;
	vector<int> ord, indegree(adj.size());
	for (int i = 0; i < adj.size(); i++) {
		for (int to : adj[i]) {
			indegree[to]++;
		}
	}
	for (int i = 0; i < adj.size(); i++) {
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
	// cycle detected
	if (ord.size() < adj.size()) {
		return vector<int>();
	}
	else {
		return ord;
	}
}