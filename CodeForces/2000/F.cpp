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
	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 1, INF);
	dp[0] = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		vector<int> minCost(k + 1, INF);
		minCost[0] = 0;
		for (int i = 0; i < k && min(x, y) > 0; i++) {
			if (min(x, y) == 1 && i <= k - 2) {
				minCost[i + 2] = minCost[i] + 1;
			}
			minCost[i + 1] = minCost[i] + min(x, y);
			if (x > y) {
				x--;
			}
			else {
				y--;
			}
		}
		for (int i = k; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j] + minCost[j]);
			}
		}
	}
	cout << (dp[k] == INF ? -1 : dp[k]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}