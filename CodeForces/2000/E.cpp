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
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> cnt(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt[i * m + j] = (min(m - 1, j + k - 1) - max(k - 1, j) + 1LL) * (min(n - 1, i + k - 1) - max(k - 1, i) + 1LL);
		}
	}
	sort(cnt.rbegin(), cnt.rend());
	int w;
	cin >> w;
	vector<ll> a(w);
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	ll tot = 0;
	for (int i = 0; i < w; i++) {
		tot += cnt[i] * a[i];
	}
	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}