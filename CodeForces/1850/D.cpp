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
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n), vis(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int mx = 1;
	for (int i = 0; i < n - 1; i++) {
		int cur = 1;
		while (i < n - 1 && a[i + 1] <= a[i] + k) {
			cur++;
			i++;
		}
		mx = max(mx, cur);
	}
	cout << n - mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
