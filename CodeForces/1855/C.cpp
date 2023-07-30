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
	cin >> n;
	int neg = 0, pos = 0;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) neg++;
		else if (a[i] > 0) pos++;
	}
	array<int, 2> mx, mn;
	mx = mn = {a[1], 1};
	for (int i = 2; i <= n; i++) {
		if (mx[0] < a[i]) mx = {a[i], i};
		if (mn[0] > a[i]) mn = {a[i], i};
	}
	
	if (mx[0] >= -mn[0] && neg <= 12) {
		cout << neg + n - 1 << '\n';
		for (int i = 1; i <= n; i++) {
			if (a[i] < 0) {
				cout << i << ' ' << mx[1] << '\n';
			}
		}
		for (int i = 2; i <= n; i++) {
			cout << i << ' ' << i - 1 << '\n';
		}
	}
	else if (mx[0] <= -mn[0] && pos <= 12) {
		cout << pos + n - 1 << '\n';
		for (int i = 1; i <= n; i++) {
			if (a[i] > 0) {
				cout << i << ' ' << mn[1] << '\n';
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			cout << i << ' ' << i + 1 << '\n';
		}
	}
	else if (neg <= pos) {
		cout << 5 + neg + n - 1 << '\n';
		for (int i = 0; i < 5; i++) {
			cout << mx[1] << ' ' << mx[1] << '\n';
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] < 0) {
				cout << i << ' ' << mx[1] << '\n';
			}
		}
		for (int i = 2; i <= n; i++) {
			cout << i << ' ' << i - 1 << '\n';
		}
	}
	else {
		cout << 5 + pos + n - 1 << '\n';
		for (int i = 0; i < 5; i++) {
			cout << mn[1] << ' ' << mn[1] << '\n';
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] > 0) {
				cout << i << ' ' << mn[1] << '\n';
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			cout << i << ' ' << i + 1 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}