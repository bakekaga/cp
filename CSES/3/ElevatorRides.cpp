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
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	vector<array<int, 2>> dp(1 << n, {n + 1, x + 1});
	dp[0] = {1, 0};
	for (int s = 1; s < (1 << n); s++) {
		for (int i = 0; i < n; i++) {
			if (s & (1 << i)) {
				auto [rides, curWeight] = dp[s ^ (1 << i)];
				if (curWeight + w[i] <= x) {
					curWeight += w[i];
				}
				else {
					rides++;
					curWeight = w[i];
				}
				dp[s] = min(dp[s], {rides, curWeight});
			}
		}
	}
	cout << dp[(1 << n) - 1][0] << '\n';
	return 0;
}