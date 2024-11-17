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
	cin >> n;
	array<int, 3> start;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		start[cur - 1]++;
	}
	vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, INF)));
	dp[0][0][0] = 0;
	for (int k = 0; k <= n; k++) {
		for (int j = 0; j <= n; j++) {
			for (int i = 0; i <= n; i++) {
				if (i + j + k > n || (i == 0 && j == 0 && k == 0)) {
					continue;
				}
				dp[i][j][k] = n;
				if (i) dp[i][j][k] += i * dp[i - 1][j][k];
				if (j) dp[i][j][k] += j * dp[i + 1][j - 1][k];
				if (k) dp[i][j][k] += k * dp[i][j + 1][k - 1];
				dp[i][j][k] /= (i + j + k);
			}
		}
	}
	cout << fixed << setprecision(10) << dp[start[0]][start[1]][start[2]] << '\n';
	return 0;
}