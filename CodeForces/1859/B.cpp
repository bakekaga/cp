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
	int n, glmn = INF;
	cin >> n;
	vector<ll> lclmn(n);
	for (int i = 0; i < n; i++) {
		int m, x, smn = INF, fmn = INF;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x < fmn) {
				smn = fmn;
				fmn = x;
			}
			else if (x < smn) {
				smn = x;
			}
		}
		lclmn[i] = smn;
		glmn = min(glmn, fmn);
	}
	cout << accumulate(lclmn.begin(), lclmn.end(), 0LL) - *min_element(lclmn.begin(), lclmn.end()) + glmn << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}