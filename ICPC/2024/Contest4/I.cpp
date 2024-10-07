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

void dfs() {

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	vector<vector<bool>> vis(n, vector<bool>(n));

	const vector<array<int, 2>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	auto inBounds = [&](int i, int j) -> bool {
		return i < n && i >= 0 && j < n && j >= 0;
	};
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '?') {
				for (auto &[dx, dy] : d) {
					array<int, 2> curPos = {i, j};
					curPos[0] += dx;
					curPos[1] += dy;
					while (inBounds(curPos[0], curPos[1]) && (grid[curPos[0]][curPos[1]] == '.' || grid[curPos[0]][curPos[1]] == '?')) {
						vis[curPos[0]][curPos[1]] = true;
						curPos[0] += dx;
						curPos[1] += dy;
					}
				}
				// for (int i = 0; i < n; i++) {
				// 	for (int j = 0; j < n; j++) {
				// 		cout << vis[i][j] << ' ';
				// 	}
				// 	cout << '\n';
				// }
				// cout << '\n';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '.') {
				ok &= vis[i][j];
			}
			else if (grid[i][j] == '?') {
				ok &= !vis[i][j];
			}
			else if (grid[i][j] == 'X') {
				continue;
			}
			else {
				int cnt = 0;
				for (auto &[dx, dy] : d) {
					if (inBounds(i + dx, j + dy) && grid[i + dx][j + dy] == '?') {
						cnt++;
					}
				}
				if (cnt != grid[i][j] - '0') {
					ok = false;
				}
			}
		}
	}
	cout << (ok ? 1 : 0) << '\n';
	return 0;
}