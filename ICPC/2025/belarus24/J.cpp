#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6;

int shoelace(vector<array<int, 2>>& polygon) {
	int n = polygon.size();
	int out = polygon[n - 1][0] * polygon[0][1] - polygon[0][0] * polygon[n - 1][1];
	for (int i = 0; i < n - 1; i++) {
		out += polygon[i][0] * polygon[i + 1][1];
	}
	for (int i = 0; i < n - 1; i++) {
		out -= polygon[i][1] * polygon[i + 1][0];
	}
	return out;
}

void solve() {
	int n, two_s;
	cin >> n >> two_s;
	if (n - 2 > two_s) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<array<int, 2>> bottom, top;
	for (int i = 0; (i + 1) * 2 < n; i++) {
		top.push_back({i, 2 - (i & 1)});
		bottom.push_back({i, 1 - (i & 1)});
	}
	if (n % 4 == 2) {
		bottom.push_back({(n - 2) / 2, 1});
		bottom.push_back({(n - 2) / 2, 1 + two_s - (n - 3)});
	} else if (n % 4 == 0) {
		for (int i = 0; (i + 1) * 2 < n; i++) {
			top[i][1] += MAXN - 2;
			bottom[i][1] += MAXN - 2;
		}
		bottom.push_back({(n - 2) / 2, MAXN - 1 - (two_s - (n - 3))});
		bottom.push_back({(n - 2) / 2, MAXN - 1});
	} else {
		bottom.push_back({(n - 2) / 2 + two_s - (n - 2) / 2 * 2, 1});
	}
	bottom.insert(bottom.end(), top.rbegin(), top.rend());
	for (int i = 0; i < bottom.size(); i++) {
		cout << bottom[i][0] << ' ' << bottom[i][1] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
