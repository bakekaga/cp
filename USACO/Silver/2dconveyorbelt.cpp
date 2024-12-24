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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<vector<char>> grid(n, vector<char>(n, '?'));
	vector<array<int, 2>> queries(q);
	for (int i = 0; i < q; i++) {
		char t;
		cin >> queries[i][0] >> queries[i][1] >> t;
		grid[--queries[i][0]][--queries[i][1]] = t;
	}

	int cnt = 0;
	vector<vector<bool>> good(n, vector<bool>(n));
	const array<int, 4> dx = {0, 1, 0, -1};
	const array<int, 4> dy = {1, 0, -1, 0};
	const array<char, 4> goodVal = {'L', 'U', 'R', 'D'};
	function<void(int, int)> dfs = [&](int x, int y) {
		if (good[x][y]) {
			return;
		}
		cnt++;
		good[x][y] = true;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || good[nx][ny]) {
				continue;
			}
			if (grid[nx][ny] == goodVal[d] || grid[nx][ny] == '?') {
				dfs(nx, ny);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (grid[i][0] == '?' || grid[i][0] == 'L') {
			dfs(i, 0);
		}
		if (grid[i][n - 1] == '?' || grid[i][n - 1] == 'R') {
			dfs(i, n - 1);
		}
		if (grid[0][i] == '?' || grid[0][i] == 'U') {
			dfs(0, i);
		}
		if (grid[n - 1][i] == '?' || grid[n - 1][i] == 'D') {
			dfs(n - 1, i);
		}
	}

	vector<int> ans(q);
	for (int i = q - 1; i >= 0; i--) {
		ans[i] = n * n - cnt;
		int x = queries[i][0];
		int y = queries[i][1];
		grid[x][y] = '?';
		bool go = false;
		if (!good[x][y]) {
			if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
				go = true;
			}
			else {
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
						continue;
					}
					if (good[nx][ny]) {
						go = true;
						break;
					}
				}
			}
		}
		if (go) {
			dfs(x, y);
		}
	}

	for (int out : ans) {
		cout << out << '\n';
	}
	return 0;
}
