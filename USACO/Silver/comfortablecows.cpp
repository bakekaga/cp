#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 2e3 + 2;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	vector<vector<bool>> grid(MAXN, vector<bool>(MAXN));
	queue<array<int, 2>> toAdd;

	auto reeval = [&](int x, int y) {
		bool comfy = false;
		array<int, 2> nbr = {-1, -1};
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (grid[nx][ny] == 0) {
				if (nbr[0] == -1) {
					comfy = true;
					nbr = {nx, ny};
				}
				else {
					comfy = false;
				}
			}
		}
		if (comfy) {
			toAdd.push({nbr[0], nbr[1]});
		}
	};

	int n, cnt = 0;
	cin >> n;
	for (int q = 1; q <= n; q++) {
		int a, b;
		cin >> a >> b;
		toAdd.push({a + 500, b + 500});
		while (!toAdd.empty()) {
			auto &[x, y] = toAdd.front();
			toAdd.pop();
			if (!grid[x][y]) {
				grid[x][y] = true;
				cnt++;
				// check if added cow and neighbors are newly comfy
				reeval(x, y);
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (grid[nx][ny]) {
						reeval(nx, ny);
					}
				}
			}
		}
		cout << cnt - q << '\n';
	}
	
	return 0;
}
