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

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<vector<int>> arr(n + 1, vector<int>(2));
	for (int i = 0; i < n; i++) {
		arr[i + 1][0] = (a[i] == 'A' ? 1 : -1);
		arr[i + 1][1] = (b[i] == 'A' ? 1 : -1);
	}
	vector<vector<int>> dp(n + 1, vector<int>(3));
	for (int i = 2; i <= n; i++) {
		if (i >= 3) {
			int dist1 = arr[i - 2][0] + arr[i - 1][0] + arr[i][0] > 0;
			int dist2 = arr[i - 2][1] + arr[i - 1][1] + arr[i][1] > 0;
			dp[i][2] = max(dp[i][2], dist1 + dist2 + dp[i - 3][2]);
		}
		for (int j = 0; j < 2; j++) {
			dp[i][j] = (arr[i - 1][j] + arr[i - 1][j ^ 1] + arr[i][j] > 0) + dp[i - 2][2];
			if (i >= 4) {
				int dist1 = arr[i - 2][j] + arr[i - 1][j] + arr[i][j] > 0;
				int dist2 = arr[i - 3][j ^ 1] + arr[i - 2][j ^ 1] + arr[i - 1][j ^ 1] > 0;
				dp[i][j] = max(dp[i][j], dist1 + dist2 + dp[i - 3][j]);
			}
			if (i >= 3) {
				dp[i][2] = max(dp[i][2], (arr[i - 1][j] + arr[i][j] + arr[i][j ^ 1] > 0) + dp[i - 1][j ^ 1]);
			}
		}
	}
	cout << dp[n][2] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}