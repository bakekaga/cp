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
	int n, W;
	cin >> n >> W;
	vector<ll> w(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	vector<ll> dp(W + 1);
	for (int i = 0; i < n; i++) {
		for (int j = W - w[i]; j >= 0; j--) {
			dp[j + w[i]] = max(dp[j] + v[i], dp[j + w[i]]);
		}
	}
	cout << dp[W] << '\n';
	return 0;
}