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
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<int> a(n);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			tot += a[i];
		}
		vector<vector<int>> dp(n, vector<int>(tot));
		for (int j = a[0]; j < sz(dp[0]); j++) {
			dp[0][j] = a[0];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < a[i]; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			for (int j = a[i]; j < sz(dp[i]); j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
			}
		}
		cout << tot - dp[n - 1][tot / 2] << ' ' << dp[n - 1][tot / 2] << '\n';
	}
}