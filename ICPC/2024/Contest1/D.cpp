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
	int n, m; cin >> n >> m;
	vector<array<int, 3>> edges(n - 1);
	vector<int> p(n), sizes(n, 1);
	iota(p.begin(), p.end(), 0);
	for (int i = 0; i < n - 1; i++) {
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
		edges[i][1]--;
		edges[i][2]--;
	}

	vector<array<int, 2>> queries(m);
	for (int i = 0; i < m; i++) {
		cin >> queries[i][0];
		queries[i][1] = i;
	}
	sort(queries.begin(), queries.end());
	sort(edges.begin(), edges.end());

	function<int(int)> get = [&](int v) -> int {
		if (v == p[v]) return v;
		return p[v] = get(p[v]);
	};

	function<void(int, int)> unite = [&](int a, int b) -> void {
		if (sizes[a] < sizes[b]) {
			swap(a, b);
		}
		p[b] = a;
		sizes[a] += sizes[b];
	};
	vector<ll> out(m);
	ll tot = 0;
	int curEdge = 0;
	for (int i = 0; i < m; i++) {
		for (int j = curEdge; j < n - 1; j++) {
			if (edges[j][0] > queries[i][0]) {
				curEdge = j;
				break;
			}
			int u = get(edges[j][1]), v = get(edges[j][2]);
			if (u != v) {
				tot += 1LL * sizes[u] * sizes[v];
				unite(u, v);
			}
		}
		if (sizes[get(0)] == n) {
			curEdge = n - 1;
		}
		out[queries[i][1]] = tot;
	}

	for (ll res : out) {
		cout << res << ' ';
	}
	return 0;
}