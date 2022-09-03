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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	vector<vector<int>> vals(n + 1, vector<int>(n + 1)), pre(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '#') vals[i + 1][j + 1]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pre[i][j] = vals[i][j]
						+ pre[i - 1][j]
						+ pre[i][j - 1]
						- pre[i - 1][j - 1];
		}
	}
	int cnt = 0;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int l = 0; l <= min(n - x1, n - y1); l++) {
				int x2 = x1 + l, y2 = y1 + l;
				if (!(pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1])) cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
