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
	vector<ll> a(n), psums(n - 1);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> diffs(n - 1);
	for (int i = 0; i < n - 1; i++) {
		diffs[i] = a[i + 1] - a[i];
	}
	if (a[n - 1] != (n + 1LL) * n / 2) {
		diffs.pb((n + 1LL) * n / 2 - a[n - 1]);
		sort(diffs.begin(), diffs.end());
		for (int i = 0; i < n - 1; i++) {
			if (diffs[i] != i + 1) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	}
	else {
		vector<int> vis(n + 1);
		ll sum = -1;
		for (int i = 0; i < n - 1; i++) {
			if (diffs[i] > n || vis[diffs[i]]) {
				if (sum != -1) {
					cout << "NO\n";
					return;
				}
				sum = diffs[i];
			}
			else {
				vis[diffs[i]]++;
			}
		}
		vector<int> gone;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) gone.pb(i);
		}
		cout << (sz(gone) == 2 ? ((gone[0] + gone[1] == sum) ? "YES\n" : "NO\n") : "NO\n"); 
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