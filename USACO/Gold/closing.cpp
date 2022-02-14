#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int comps;

struct DSU {
	vector<int> par, sz;
	DSU(int N) {
        par = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
    }

	// get representive component (uses path compression)
	int get(int v) {
		if (v == par[v]) return v;
		return par[v] = get(par[v]);
	}

	// union by size
	void unite(int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
            comps--;
			if (sz[a] < sz[b]) swap(a, b);
			par[b] = a;
			sz[a]+= sz[b];
		}
	}
	
	bool same_set(int a, int b) {
        return get(a) == get(b);
    }
	
	int size(int v) {
        return sz[get(v)];
    }
};

vector<int> adj[MAXN];
pair<int, vector<int>> ord[MAXN];
bool vis[MAXN];

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> ord[i].first;
        ord[i].first--;
        vis[ord[i].first] = true;
        for (int node : adj[ord[i].first]) {
            if (!vis[node]) ord[i].second.pb(node);
        }
    }

    DSU dsu(n);
    vector<string> out(n);

    for (int i = n - 1; i >= 0; i--) {
        comps++;
        for (int node : ord[i].second) {
            dsu.unite(node, ord[i].first);
        }
        out[i] = comps <= 1 ? "YES\n" : "NO\n";
    }

    for (int i = 0; i < n; i++) {
        cout << out[i];
    }
    return 0;
}