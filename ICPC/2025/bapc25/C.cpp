#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr double max_radius = 160 / 2;
constexpr double max_dist = 25.4 * 2;
constexpr double eps = 1e-5;

struct Point {
	double x, y;
	double r;
};

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct DSU {
	vector<int> p;
	vector<int> sizes;

	DSU(int n) : p(n), sizes(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int get(int u) {
		if (p[u] == u) {
			return u;
		}
		return (p[u] = get(p[u]));
	}

	void unite(int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
			if (sizes[a] < sizes[b]) {
				swap(a, b);
			}
			p[b] = a;
			sizes[a] += sizes[b];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<Point> points(n);
	map<double, set<pair<double, int>>> cols;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y >> points[i].r;
		points[i].r /= 2;
		cols[points[i].x].insert({points[i].y, i});
	}

	vector<vector<int>> adj(n);
	DSU dsu(n);

	for (int i = 0; i < n; i++) {
		auto [x, y, r] = points[i];
		// get all cols within [x - (max_radius + r + 2 * 25.4), x)
		auto it = cols.upper_bound(x - (r + max_radius + max_dist) - eps);
		for (; it->first + eps < x; it++) {
			auto& ys = it->second;
			double max_bound = sqrt((r + max_radius + max_dist) * (r + max_radius + max_dist) - (x - it->first) * (x - it->first));
			// cout << x << ": " << y - max_bound << ", " << y + max_bound << '\n';
			auto lb = ys.upper_bound({y - max_bound - eps, -1});
			auto ub = ys.upper_bound({y + max_bound + eps, n + 1});
			for (auto it_ys = lb; it_ys != ub; it_ys++) {
				auto [other_x, other_y, other_r] = points[it_ys->second];
				// cout << it_ys->second << "; " << dist(x, y, other_x, other_y) << ", " << r + other_r + max_dist << "\n";
				if (dist(x, y, other_x, other_y) - eps <= r + other_r + max_dist) {
					adj[i].push_back(it_ys->second);
					adj[it_ys->second].push_back(i);
					dsu.unite(i, it_ys->second);
				}
			}
		}
		// get all models that share x
		auto& ys = it->second;
		for (auto it_ys = ys.upper_bound({y - r - max_radius - max_dist - eps, -1}); it_ys->first + eps < y; it_ys++) {
			auto [other_x, other_y, other_r] = points[it_ys->second];
			if (y - other_y - eps <= (r + other_r + max_dist)) {
				adj[i].push_back(it_ys->second);
				adj[it_ys->second].push_back(i);
				dsu.unite(i, it_ys->second);
			}
		}
	}

	if (dsu.sizes[dsu.get(0)] < n) {
		cout << "no\n";
	} else {
		if (n < 7) {
			cout << "yes\n";
		} else {
			for (int i = 0; i < n; i++) {
				if (adj[i].size() < 2) {
					cout << "no\n";
					return 0;
				}
			}
			cout << "yes\n";
		}
	}
	return 0;
}