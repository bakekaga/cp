// Floodfill/implementation problem. The hard part is figuring out how to create the grid,
// and then using an ITERATIVE depth first search to traverse it and keep track of the number
// of disconnected regions; the answer is that number minus one because we need one gate to
// connect two regions, and the outer region counts. Recursive dfs will stack overflow in
// this problem.

#include <bits/stdc++.h>

#define MAXN 1000
#define mp make_pair

using namespace std;
typedef long long ll;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

bool grid[4 * MAXN + 1][4 * MAXN + 1];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
    fileIO("gates");

    string path = "";
    int n;
    cin >> n >> path;

    pair<int,int> john = mp(2*MAXN, 2*MAXN);
    grid[john.first][john.second] = true;
    for (int i = 0; i < path.size(); i++) {
        int addx = 0, addy = 0;
        if (path[i] == 'N') {
            addy = 1;
        }
        else if (path[i] == 'S') {
            addy = -1;
        }
        else if (path[i] == 'E') {
            addx=1;
        }
        else if (path[i] == 'W') {
            addx = -1;
        }
        for (int j = 0; j < 2; j++) {
            john.first += addx;
            john.second += addy;
            grid[john.first][john.second] = true;
        }
    }

    int out = -1, dim = sizeof(grid)/sizeof(grid[0]);

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (grid[i][j]) continue;
            out++;
            queue<pair<int,int>> q;
            q.push(mp(i,j));
            while (!q.empty()) {
                if (q.front().first >= 0 && q.front().second >= 0
                && q.front().first < dim && q.front().second < dim
                && !grid[q.front().first][q.front().second]) {
                    grid[q.front().first][q.front().second] = true;
                    for(int k = 0; k < 4; k++) {
                        q.push(mp(q.front().first + dx[k], q.front().second + dy[k]));
                    }
                }
                q.pop();
            }
        }
    }
    
    cout << out << '\n';

    return 0;
}