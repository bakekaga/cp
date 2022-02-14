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

struct DSU {
	vector<int> par, sz;
    int comps;
	DSU(int N) {
        par = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
        comps = N;
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
			if (sz[a] < sz[b]) swap(a, b);
			par[b] = a;
			sz[a]+= sz[b];
            comps--;
		}
	}
	
	bool same_set(int a, int b) {
        return get(a) == get(b);
    }
	
	int size(int v) {
        return sz[get(v)];
    }
};

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin >> n;
    vector<pair<ll, ll>> vertices(n);
    vector<pair<ll, pair<int, int>>> distances;
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            distances.pb({(vertices[i].second - vertices[j].second) * (vertices[i].second - vertices[j].second) + (vertices[i].first - vertices[j].first) * (vertices[i].first - vertices[j].first), {i, j}});
        }
    }
    sort(distances.begin(), distances.end());

    DSU dsu(n);
    for (auto x : distances) {
        dsu.unite(x.second.first, x.second.second);
        if (dsu.comps == 1) {
            cout << x.first << '\n';
            break;
        }
    }
    return 0;
}
