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

int calcBalloons(int time, int t, int y, int z) {
	return time / (t * z + y) * z + min(z, time % (t * z + y) / t);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n; cin >> m >> n;
	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][2] >> a[i][1];
	}
	int l = 0, r = 3e7, tot = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		tot = 0;
		for (int i = 0; i < n; i++) {
			tot += calcBalloons(mid, a[i][0], a[i][1], a[i][2]);
		}
		if (tot >= m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
	tot = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur = calcBalloons(l, a[i][0], a[i][1], a[i][2]);
		if (tot + cur > m) {
			cur = m - tot;
		}
		tot += cur;
		cout << cur << ' ';
	}
	return 0;
}