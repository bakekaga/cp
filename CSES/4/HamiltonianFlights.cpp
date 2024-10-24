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
	vector<vector<int>> revAdj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		revAdj[--b].pb(--a);
	}

	vector<vector<ll>> dp(1 << n, vector<ll>(n));
	dp[1][0] = 1;
	for (int s = 2; s < (1 << n); s++) {
		if (!(s & 1) || ((s & (1 << (n - 1)) && s != (1 << n) - 1))) {
			continue;
		}
		for (int to = 0; to < n; to++) {
			if (!(s & (1 << to))) {
				continue;
			}
			for (int from : revAdj[to]) {
				dp[s][to] += dp[s ^ (1 << to)][from];
				dp[s][to] %= MOD;
			}
		}
	}
	
	cout << dp[(1 << n) - 1][n - 1] << '\n';
	return 0;
}