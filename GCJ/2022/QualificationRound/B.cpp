#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

void solve() {
	array<array<int, 4>, 3> v;
	array<int, 4> mn;
	mn.fill(MAXN + 5);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> v[i][j];
			mn[j] = min(mn[j], v[i][j]);
		}
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) sum+= mn[i];
	if (sum < MAXN) cout << "IMPOSSIBLE\n";
	else {
		array<pair<int, int>, 4> smn;
		for (int i = 0; i < 4; i++) smn[i] = {mn[i], i};
		sort(smn.begin(), smn.end());
		sum = 0;
		int breakpoint = 0;
		for (int i = 0; i < 4; i++) {
			sum+= smn[i].first;
			if (sum >= MAXN) {
				breakpoint = i;
				break;
			}
		}
		mn[smn[breakpoint].second]-= (sum - MAXN);
		for (int i = breakpoint + 1; i < 4; i++) {
			mn[smn[i].second] = 0;
		}
		for (int i = 0; i < 4; i++) cout << mn[i] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}