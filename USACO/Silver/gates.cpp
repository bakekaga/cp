// Floodfill/implementation problem. The hard part is figuring out how to create the grid,
// and then using an ITERATIVE depth first search to traverse it and keep track of the number
// of disconnected regions; the answer is that number minus one because we need one gate to
// connect two regions, and the outer region counts. Recursive dfs will stack overflow in
// this problem.

#include <bits/stdc++.h>
#define MAXN 1005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

vector<vector<int>> grid;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < sz(grid) && y < sz(grid) && !grid[x][y];
}

void dfs(int x, int y) {
    grid[x][y]++;
    for (int i = 0; i < 4; i++) {
        if (ok(x + dx[i], y + dy[i])) dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int n; cin >> n;
    string s; cin >> s;
    pair<int, int> john = mp(n + 2, n + 2);
    grid = vector<vector<int>>(2 * n + 5, vector<int>(2 * n + 5, 0));
    grid[john.first][john.second]++;

    for (int i = 0; i < n; i++) {
        int addx = 0, addy = 0;
        if (s[i] == 'N') addy++;
        else if (s[i] == 'E') addx++;
        else if (s[i] == 'W') addx--;
        else if(s[i] == 'S') addy--;
        for (int j = 0; j < 2; j++) {
            john.first+= addx;
            john.second+= addy;
            grid[john.first][john.second]++;
        }
    }
	
    int cnt = -1;
    for (int i = 0; i < sz(grid); i++) {
        for (int j = 0; j < sz(grid); j++) {
            if (grid[i][j]) continue;
            cnt++;
            dfs(i, j);
        }
    }

    cout << cnt << '\n';
    return 0;
}