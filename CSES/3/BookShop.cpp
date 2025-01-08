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
	int n, x;
	cin >> n >> x;
	vector<int> weights(n + 1), values(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> weights[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> values[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(x + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - weights[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
			}
		}
	}
	cout << dp[n][x] << '\n';
	return 0;
}