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
	int n; cin >> n;
	vector<vector<ll>> mat(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = mat[0][0];
			}
			else if (mat[i - 1][j - 1] == -1 || (dp[i - 1][j] == -1 && dp[i][j - 1] == -1)) {
				continue;
			}
			else {
				dp[i][j] = mat[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n][n] << '\n';
	return 0;
}