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
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 3) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}