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
	vector<ll> w(n);
	for (int i = 0; i < n; i++) cin >> w[i];
	int ai = 0, bi = n - 1, ans = 0;
	ll aTot = w[ai], bTot = w[bi];
	while (ai < bi) {
		if (aTot < bTot) {
			ai++;
			aTot+= w[ai];
		}
		else if (aTot > bTot) {
			bi--;
			bTot+= w[bi];
		}
		else {
			ans = ai + 1 + n - bi;
			bi--;
			bTot+= w[bi];
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}