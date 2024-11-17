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
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '#') continue;
			if (i) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[n - 1][m - 1] << '\n';
	return 0;
}