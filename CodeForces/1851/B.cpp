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
	vector<int> odd, even, a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] & 1) {
			odd.pb(i);
		}
		else {
			even.pb(i);
		}
	}
	sort(a.begin(), a.end());
	// for (auto i : odd) cout << i << ' ';
	// cout << '\n';
	// for (auto i : even) cout << i << ' ';
	// cout << '\n';
	for (int i = 0, j = 0; i < sz(odd) && j < sz(even);) {
		// cout << i << ' ' << j << '\n';
		if ((a[i + j] & 1) && odd[i] == i + j) {
			i++;
		}
		else if (!(a[i + j] & 1) && even[j] == i + j) {
			j++;
		}
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}