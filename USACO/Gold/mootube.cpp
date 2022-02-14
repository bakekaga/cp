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

struct Q {
    ll k;
    int id, v;
};

struct E {
    ll r;
    int a, b;
};

bool cmpE(const E &a, const E &b) {
    return a.r > b.r;
}

bool cmpQ(const Q &a, const Q &b) {
    return a.k > b.k;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q; cin >> n >> q;
    vector<E> edges(n - 1);
    vector<Q> queries(q);
    vector<int> ret(q);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].r;
        edges[i].a--;
        edges[i].b--;
    }
    for (int i = 0; i < q; i++) {
        cin >> queries[i].k >> queries[i].v;
        queries[i].v--;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end(), cmpQ);
    sort(edges.begin(), edges.end(), cmpE);
    
    DSU dsu(n);
    for (int i = 0, j = 0; i < q; i++) {
        for (; j < n - 1 && edges[j].r >= queries[i].k; j++) {
            dsu.unite(edges[j].a, edges[j].b);
        }
        ret[queries[i].id] = dsu.size(queries[i].v) - 1;
    }

    for (int i = 0; i < q; i++) {
        cout << ret[i] << '\n';
    }

    return 0;
}