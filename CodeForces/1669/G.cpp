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
	int n, m; cin >> n >> m;
	vector<vector<char>> v(n + 2, vector<char>(m));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) cin >> v[i][j];
	}
	fill(v[n + 1].begin(), v[n + 1].end(), 'o');
	for (int i = 0; i < m; i++) {
		int dots = 0, lastObs = 0;
		for (int j = 1; j <= n + 1; j++) {
			if (v[j][i] == '.') dots++;
			else if (v[j][i] == 'o') {
				for (int k = lastObs + 1; k <= lastObs + dots; k++) v[k][i] = '.';
				for (int k = lastObs + dots + 1; k < j; k++) v[k][i] = '*';
				lastObs = j;
				dots = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) cout << v[i][j];
		cout << '\n';
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