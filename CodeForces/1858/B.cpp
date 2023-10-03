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
	ll n, d;
	int m;
	cin >> n >> m >> d;
	vector<ll> sellers(m + 2);
	sellers[0] = 1 - d;
	sellers[m + 1] = n + 1;
	for (int i = 1; i <= m; i++) {
		cin >> sellers[i];
	}
	ll tot = m, cnt = 1, mn = n;
	for (int i = 0; i <= m; i++) {
		tot += (sellers[i + 1] - sellers[i] - 1) / d;
	}
	for (int i = 1; i <= m; i++) {
		ll cur = (sellers[i + 1] - sellers[i - 1] - 1) / d - (sellers[i] - sellers[i - 1] - 1) / d - (sellers[i + 1] - sellers[i] - 1) / d;
		if (mn > cur) {
			mn = cur;
			cnt = 1;
		}
		else if (mn == cur) {
			cnt++;
		}
	}
	cout << tot - 1 + mn << ' ' << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}