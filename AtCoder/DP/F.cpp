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
	string a, b;
	cin >> a >> b;
	int n = sz(a), m = sz(b);
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	string ret;
	while (n && m) {
		if (a[n - 1] == b[m - 1]) {
			ret = a[n - 1] + ret;
			n--;
			m--;
		}
		else if (dp[n - 1][m] > dp[n][m - 1]) {
			n--;
		}
		else {
			m--;
		}
	}
	cout << ret << '\n';
	return 0;
}