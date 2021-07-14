// Dumb impl-heavy search (DFS or BFS works) problem. At every square we light every
// square that has not been lit, check if the squares that have just been lit have any 
// adjacent visited squares, and then afterwards check if the square has any adjacent lit
// but unvisited squares. We need the second step to cover any squares that could have
// been missed previously and can now be reached, and the third step is in order to move on.


#include <bits/stdc++.h>

#define MAXN 100

using namespace std;
typedef long long ll;

vector<pair<int, int>> grid[MAXN][MAXN];
bool visited[MAXN][MAXN], on[MAXN][MAXN];
int number = 1, n;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

bool isVisitedOn(int x, int y, bool which) {
    return x >= 0 && x < n && y >= 0 && y < n && ((which) ? visited[x][y] : on[x][y]);
}

bool neighborVisited(int x, int y) {
    return isVisitedOn(x - 1, y, true) || isVisitedOn(x, y + 1, true) || isVisitedOn(x, y - 1, true) || isVisitedOn(x + 1, y, true);
}

void dfs(int i, int j) {
    visited[i][j] = true;
    for (auto point : grid[i][j]) {
        if (!on[point.first][point.second]) {
            on[point.first][point.second] = true;
            number++;
            if (neighborVisited(point.first, point.second)) dfs(point.first, point.second);
        }
    }
    if (!isVisitedOn(i - 1, j, true) && isVisitedOn(i - 1, j, false)) dfs(i - 1, j);
    if (!isVisitedOn(i, j + 1, true) && isVisitedOn(i, j + 1, false)) dfs(i, j + 1);
    if (!isVisitedOn(i, j - 1, true) && isVisitedOn(i, j - 1, false)) dfs(i, j - 1);
    if (!isVisitedOn(i + 1, j, true) && isVisitedOn(i + 1, j, false)) dfs(i + 1, j);
}

int main() {    
    fileIO("lightson");

    int m;
    cin >> n >> m;

    on[0][0] = true;

    for (int i = 0; i < m; i++) {
        pair<int, int> a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        b.first--; b.second--;
        grid[a.first - 1][a.second - 1].push_back(b);
    }

    dfs(0, 0);
    cout << number << '\n';
    return 0;
}