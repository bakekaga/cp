#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

constexpr int MAXD = 1e9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	map<int, set<int>> points;
	int min_y = INF;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[x].insert(y);
		min_y = min(min_y, y);
	}

	// vertical line, n >= 3 guarantees distinct max, min y
	if (points.size() == 1) {
		auto& [x, y_vals] = *points.begin();
		int max_y = *y_vals.rbegin();
		if (x == MAXD) {
			points[x - 1].insert(min_y);
			points[x - 1].insert(max_y);
		} else {
			points[x + 1].insert(min_y);
			points[x + 1].insert(max_y);
		}
	}

	int l = points.begin()->first;
	int r = prev(points.end())->first;
	if (min_y == MAXD) {
		min_y--;
	}
	points[l].insert(min_y);
	points[r].insert(min_y);

	// if nothing to project
	if (points[l].size() == 1) {
		points[l].insert(min_y + 1);
	}
	if (points[r].size() == 1) {
		points[r].insert(min_y + 1);
	}

	for (auto& [x, y_vals] : points) {
		if (x == l) {  // project all points to the left except leftmost
			if (!points.count(x + 1)) {
				points[x + 1].insert(min_y + 1);
			}
		} else if (x == r) {
			if (!points.count(x - 1)) {
				points[x - 1].insert(min_y + 1);
			}
		} else {
			if (!points.count(x - 1)) {
				points[x - 1].insert(min_y + 1);
			}
			points[x].insert(min_y + 1);
		}
	}

	vector<pair<int, int>> ord;
	for (auto& [x, y_vals] : points) {
		if (x == l) {
			for (int y : y_vals) {
				if (y != min_y) {
					ord.push_back({x, y});
				}
			}
		} else {
			for (auto it = y_vals.rbegin(); it != y_vals.rend(); it++) {
				if (*it != min_y) {
					ord.push_back({x, *it});
				}
			}
		}
	}

	// points on bottom
	for (auto it = points.rbegin(); it != points.rend(); it++) {
		if (it->second.count(min_y)) {
			ord.push_back({it->first, min_y});
		}
	}

	cout << ord.size() << '\n';
	for (auto& [x, y] : ord) {
		cout << x << ' ' << y << '\n';
	}
	return 0;
}