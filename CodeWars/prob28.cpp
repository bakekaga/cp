#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

char maze[MAXN][MAXN];
pair<int, int> dist[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> m >> n;
	pair<int, int> start, end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'T') {
				start = {i, j};
			}
			if (maze[i][j] == 'D') {
				end = {i, j};
			}
		}
	}

	memset(dist, -1, sizeof dist);
	queue<pair<int, int>> bfs;
	dist[start.first][start.second].first = 0;
	bfs.push(start);
	while (!bfs.empty()) {
		pair<int, int> cur = bfs.front();
		bfs.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i], y = cur.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (!vis[x][y]) {
				vis[x][y]++;
				if (maze[x][y] != 'W') {
					bfs.push({x, y});
					dist[x][y] = {dist[cur.first][cur.second].first + 1, i};
				}
			}
		}
	}

	cout << dist[end.first][end.second].first << '\n';
	return 0;
}