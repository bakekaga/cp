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
	int n, m; cin >> n >> m;
	pair<int, int> start, dest;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'A') {
				start = {i, j};
			}
			if (maze[i][j] == 'B') {
				dest = {i, j};
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
				if (maze[x][y] != '#') {
					bfs.push({x, y});
					dist[x][y] = {dist[cur.first][cur.second].first + 1, i};
				}
			}
		}
	}

	if (dist[dest.first][dest.second].first != -1) {
		cout << "YES\n" << dist[dest.first][dest.second].first << '\n';
		vector<char> out;
		for (int i = dest.first, j = dest.second; mp(i, j) != start;) {
			if (dist[i][j].second == 0) {
				out.pb('D');
				i--;
			}
			else if (dist[i][j].second == 1) {
				out.pb('U');
				i++;
			}
			else if (dist[i][j].second == 2) {
				out.pb('R');
				j--;
			}
			else {
				out.pb('L');
				j++;
			}
		}
		for (int i = sz(out) - 1; i >= 0; i--) cout << out[i];
	}
	else cout << "NO\n";
	return 0;
}