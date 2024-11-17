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
	vector<ll> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<ll> dp(n, INF);
	dp[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		dp[i + 1] = min(dp[i + 1], abs(h[i + 1] - h[i]) + dp[i]);
		if (i < n - 2) dp[i + 2] = min(dp[i + 2], abs(h[i + 2] - h[i]) + dp[i]);
	}
	cout << dp[n - 1] << '\n';
	return 0;
}