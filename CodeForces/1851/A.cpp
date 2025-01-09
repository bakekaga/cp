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
	ll H;
	cin >> n >> m >> k >> H;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		x-= H;
		if (x != 0 && x % k == 0 && x < m * k && x > -m * k) {
			cnt++;
		}
	}
	cout << cnt << '\n';
}
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}