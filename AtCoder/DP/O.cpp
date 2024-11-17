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
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	
	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int s = 0; s < (1 << n); s++) {
		int pairs = __builtin_popcount(s);
		for (int i = 0; i < n; i++) {
			if ((s & (1 << i)) || !adj[pairs][i]) continue;

			dp[s | (1 << i)] += dp[s];
			dp[s | (1 << i)] %= MOD;
		}
	}
	
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}