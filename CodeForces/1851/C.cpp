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
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	vector<int> s(1), e(1, n - 1);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (i > 0 && c[i] == c[0]) {
			s.pb(i);
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (c[i] == c[n - 1]) {
			e.pb(i);
		}
	}
	if (sz(s) < k || sz(e) < k) cout << "NO\n";
	else if (c[0] == c[n - 1]) cout << "YES\n";
	else cout << (s[k - 1] < e[k - 1] ? "YES\n" : "NO\n");
}
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}