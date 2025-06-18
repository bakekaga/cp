#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

// To get the shortest length shortest path, add EPS < smallest weight to each weight

// To solve SSSP for undirected graph, just transform {u, v} into (u, v) and (v, u)
// and apply dijkstra; if a negative edge weight exists then we can get arbitrarily
// small paths

// DIJKSTRA ALGORITHM IN O(m log n) FOR NONNEGATIVE WEIGHTS

vector<ll> dijkstra(int s, vector<vector<pair<int, ll>>> &adj) {
    int n = adj.size();
    vector<ll> d(n, INF);
    // if we want to reconstruct any shortest path
    vector<int> p(n, -1);
    d[s] = 0;
    // can also omit comparator and use negative weights
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        // check if this node already has a value assigned
        if (d_v != d[v])
            continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    return d;
}

// 0-1 BFS IN O(m) FOR 0 OR 1 WEIGHTS

vector<ll> bfs(int s, vector<vector<pair<int, ll>>> &adj) {
    int n = adj.size();
    vector<ll> d(n, INF);
    // if we want to reconstruct any shortest path
    vector<int> p(n, -1);
    
    d[s] = 0;
    // can also omit comparator and use negative weights
    deque<int> q;
	q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
    	q.pop_front();
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
				if (len == 1)
					q.push_back(to);
				else
					q.push_front(to);
            }
        }
    }
    return d;
}

// BELLMAN-FORD ALGORITHM IN O(nm) FOR NEGATIVE WEIGHTS

struct Edge {
    int a, b;
    int cost;
};

vector<int> bellmanFord(int s, int n, vector<Edge> edges) {
    vector<int> d(n, INF);
    vector<int> p(n, -1);
	d[s] = 0;
    int found;
    for (int i = 0; i < n; i++) {
        found = -1;
        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    // if there is a negative cycle, need to avoid
                    // integer underflow
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    found = e.b;
                }
        // if no relaxation made in an iteration, can exit early
        if (found == -1) {
            return d;
        }
    }
    // if relaxation can still be made after n - 1 iterations,
    // there must be a negative cycle
    int y = found;
    for (int i = 0; i < n; ++i)
        y = p[y];

    vector<int> path;
    for (int cur = y; !(cur == y && path.size() > 1); cur = p[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

// SPFA IN O(nm) FOR NEGATIVE WEIGHTS

vector<int> spfa(int s, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> d(n, INF);
    vector<int> cnt(n), p(n, -1);
    vector<bool> inqueue(n);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;

                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    // negative cycle detected
                    if (cnt[to] > n) {
                        int y = to;
                        for (int i = 0; i < n; ++i)
                            y = p[y];

                        vector<int> path;
                        for (int cur = y; !(cur == y && path.size() > 1); cur = p[cur]) {
                            path.push_back(cur);
                        }
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }
    }
    return d;
}
