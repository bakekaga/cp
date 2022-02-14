#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb pusv_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<ll, int>> v(n);
	vector<ll> a(n);
    for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[i] = {a[i], i};
	}
    sort(v.begin(), v.end(), greater<>());
	DSU dsu(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
		if (v[i].second < n - 1 && a[v[i].second + 1] >= v[i].first) dsu.unite(v[i].second, v[i].second + 1);
		if (v[i].second > 0 && a[v[i].second - 1] >= v[i].first) dsu.unite(v[i].second, v[i].second - 1);
		ans = max(ans, v[i].first * dsu.size(v[i].second));
	}
    cout << ans << '\n';
    return 0;
}