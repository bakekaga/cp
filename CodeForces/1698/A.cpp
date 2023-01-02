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
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll x = a[1];
	for (int j = 2; j < n; j++) {
		x^= a[j];
	}
	if (x == a[0]) {
		cout << x << '\n';
	}
	else {
		for (int i = 1; i < n; i++) {
			x = a[0];
			for (int j = 1; j < n; j++) {
				if (i == j) continue;
				x^= a[j];
			}
			if (x == a[i]) {
				cout << x << '\n';
				break;
			}
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