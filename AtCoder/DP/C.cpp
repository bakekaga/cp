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
	vector<array<int, 3>> dp(2);
	array<int, 3> v;
	for (int i = 0; i < n; i++) {
		cin >> v[0] >> v[1] >> v[2];
		for (int j = 0; j < 3; j++) {
			dp[i & 1][j] = v[j] + max(dp[(i & 1) ^ 1][(j + 1) % 3], dp[(i & 1) ^ 1][(j + 2) % 3]);
		}
		dp[(i & 1) ^ 1] = {0, 0, 0};
	}
	cout << max(dp[(n + 1) % 2][0], max(dp[(n + 1) % 2][1], dp[(n + 1) % 2][2])) << '\n';
	return 0;
}