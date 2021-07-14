#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

// binary search + DSU solution

struct DSU {
	vector<int> e;
	DSU(int N) {
        e = vector<int>(N, -1);
    }

	// get representive component (uses path compression)
	int get(int x) {
        if (e[x] < 0) return x;
        else return e[x] = get(e[x]);
    }
	
	bool same_set(int a, int b) {
        return get(a) == get(b);
    }
	
	int size(int x) {
        return -e[get(x)];
    }
	
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

struct Edge {
    int a, b, w;
};

int perm[MAXN];
Edge edge[MAXN];

bool ok(int minw, int n, int m) {
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        if (edge[i].w >= minw) dsu.unite(edge[i].a, edge[i].b);
    }
    for (int i = 0; i < n; i++) {
        if (!dsu.same_set(perm[i], i)) return false;
    }
    return true;
}

bool cmp(const Edge &a, const Edge &b) {
    return a.w > b.w;
}

int main() {
    setIO("wormsort");

    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> perm[i]; perm[i]--;
    }
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edge[i].a = a-1; edge[i].b = b-1; edge[i].w = w;
    }

    int minw = 0, maxw = 1000000001, ret = -1;
    while(minw <= maxw) {
        int mid = (minw + maxw) / 2;
        if(ok(mid, n, m)) {
            ret = max(mid, ret);
            minw = mid + 1;
        }
        else maxw = mid - 1;
    }
    if (ret > 1000000000) ret = -1;
    cout << ret << endl;
    return 0;
}

// binary search + DFS solution

// bool vis[MAXN];
// vector<vector<int>> comps;
// int compid[MAXN];
// vector<pair<int, int>> adj[MAXN];
// int perm[MAXN];

// void dfs(int minw, int cur, int icomp) {
//     if (vis[cur]) return;
//     vis[cur] = true;
//     comps[icomp].pb(cur);
//     compid[cur] = icomp;
//     for (auto c : adj[cur]) {
//         if (c.second >= minw && !vis[c.first]) dfs(minw, c.first, icomp);
//     }
// }

// bool ok(int minw, int n) {
//     comps.clear();
//     fill(compid, compid+n, -1);
//     fill(vis, vis+n, false);
//     int j = 0;
//     for (int i = 0; i < n; i++) {
//         if (!vis[i]) {
//             vector<int> v;
//             comps.pb(v);
//             dfs(minw, i, j);
//             j++;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (compid[i] != compid[perm[i]]) return false;
//     }
//     return true;
// }

// int main() {
//     setIO("wormsort");

//     int n, m; cin >> n >> m;
    
//     for (int i = 0; i < n; i++) {
//         cin >> perm[i]; perm[i]--;
//     }
//     for (int i = 0; i < m; i++) {
//         int a, b, w; cin >> a >> b >> w;
//         adj[a-1].pb(mp(b-1, w));
//         adj[b-1].pb(mp(a-1, w)); 
//     }

//     int minw = 0, maxw = 1000000001, ret = -1;
//     while(minw <= maxw) {
//         int mid = (minw + maxw) / 2;
//         if(ok(mid, n)) {
//             ret = max(mid, ret);
//             minw = mid + 1;
//         }
//         else maxw = mid - 1;
//     }
//     if (ret > 1000000000) ret = -1;
//     cout << ret << endl;
//     return 0;
// }
