// Dumb impl-heavy search (DFS or BFS works) problem. At every square we light every
// square that has not been lit, check if the squares that have just been lit have any 
// adjacent visited squares, and then afterwards check if the square has any adjacent lit
// but unvisited squares. We need the second step to cover any squares that could have
// been missed previously and can now be reached, and the third step is in order to move on.

#include <bits/stdc++.h>
#define MAXN 100
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

vector<pair<int, int>> switches[MAXN][MAXN];
int vis[MAXN][MAXN], on[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < 100 && y < 100 && !vis[x][y] && on[x][y];
}

bool oklight(int x, int y) {
    return x >= 0 && y >= 0 && x < 100 && y < 100 && vis[x][y];
}

void dfs(int x, int y) {
    vis[x][y]++;
    for (auto light : switches[x][y]) {
        if (!on[light.first][light.second]) {
            on[light.first][light.second]++;
            for (int i = 0; i < 4; i++) {
                if (oklight(light.first + dx[i], light.second + dy[i])) {
                    dfs(light.first + dx[i], light.second + dy[i]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (ok(x + dx[i], y + dy[i])) dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        switches[x - 1][y - 1].pb(mp(a - 1, b - 1));
    }

    on[0][0]++;
    dfs(0, 0);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (on[i][j]) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}