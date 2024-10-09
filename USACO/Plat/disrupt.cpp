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

using edge = array<int, 3>;

struct Subtree {
	priority_queue<edge, vector<edge>, greater<edge>> heap;
	set<int> incl;
};

int main() {
	freopen("disrupt.in", "r", stdin);
	freopen("disrupt.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<array<int, 2>> ord;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
		ord.pb({a, b});
	}

	vector<vector<array<int, 2>>> extraAdj(n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		extraAdj[--a].pb({--b, w});
		extraAdj[b].pb({a, w});
	}

	vector<Subtree> subtrees(n);
	map<array<int, 2>, int> out;
	function<void(int, int)> dfs = [&](int cur, int par) {
		for (int chld : adj[cur]) {
			if (chld == par) continue;
			dfs(chld, cur);
			if (subtrees[chld].heap.size() > subtrees[cur].heap.size()) {
				swap(subtrees[cur], subtrees[chld]);
			}
			for (auto i : subtrees[chld].incl) {
				subtrees[cur].incl.insert(i);
			}
			while (!subtrees[chld].heap.empty()) {
				edge curEdge = subtrees[chld].heap.top();
				subtrees[cur].heap.push(curEdge);
				subtrees[chld].heap.pop();
			}
		}
		subtrees[cur].incl.insert(cur);
		while (!subtrees[cur].heap.empty()) {
			edge curEdge = subtrees[cur].heap.top();
			if (subtrees[cur].incl.count(curEdge[2])) {
				subtrees[cur].heap.pop();
			}
			else {
				break;
			}
		}
		for (auto [nbr, w] : extraAdj[cur]) {
			if (!subtrees[cur].incl.count(nbr)) {
				subtrees[cur].heap.push({w, cur, nbr});
			}
		}
		out[{cur, par}] = out[{par, cur}] = subtrees[cur].heap.empty() ? -1 : subtrees[cur].heap.top()[0];
	};

	dfs(0, -1);

	for (auto [a, b] : ord) {
		cout << out[{a, b}] << '\n';
	}
	return 0;
}