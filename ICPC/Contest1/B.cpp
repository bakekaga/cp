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
int vis[MAXN], ans[MAXN];
pair<int, int> p;

set<pair<int, int>> edges;
bool cyc;
void dfs2(int prev, int cur) {
	vis[cur]++;
	for (int x : adj[cur]) {
		if (edges.count(mp(x, cur))) {
			cyc = false;
			p.first = x;
			p.second = cur;
		}
		else {
			edges.insert(mp(x, cur));
			if (x != prev) {
				if (!vis[x]) dfs2(cur, x);
				else {
					cyc = true;
					p.first = x;
					p.second = cur;
				}
			}
		}
	}
}

void dfs3(int prev, int cur) {
	ans[cur] = prev;
	for (int x : adj[cur]) {
		if (!ans[x] && ((cyc && !(cur == p.first && x == p.second)) || !cyc)) {
			dfs3(cur, x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	set<pair<int, int>> roads;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!ans[i]) {
			edges.clear();
			dfs2(-1, i);
			dfs3(p.second, p.first);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << ans[i] << '\n';
	}
	return 0;
}