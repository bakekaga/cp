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
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	int cnt = 0;
	int unmatched = 0;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		cnt += cur / 2;
		unmatched += cur % 2; 
	}
	// if unmatched + cnt > r, then unmatched + cnt - r ppl r unhappy
	cout << unmatched + 2 * cnt - 2 * max(0, unmatched + cnt - r) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}