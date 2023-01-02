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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				cnt++;
				stack<pair<int, int>> dfs;
				dfs.push({i, j});
				while (!dfs.empty()) {
					pair<int, int> cur = dfs.top();
					dfs.pop();
					grid[cur.first][cur.second] = '#';
					for (int k = 0; k < 4; k++) {
						int x = cur.first + dx[k], y = cur.second + dy[k];
						if (x < 0 || y < 0 || x >= n || y >= m) continue;
						if (grid[x][y] == '.') {
							dfs.push({x, y});
						}
					}
				}
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}