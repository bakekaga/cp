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
	vector<array<int, 2>> a(n);
	for (int i = 0; i < n ; i++) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	
	sort(a.begin(), a.end());
	array<int, 2> mn = {(1 << k), -1};
	for (int i = 0; i < n - 1; i++) {
		if (mn[0] > (a[i][0] ^ a[i + 1][0])) {
			mn[0] = a[i][0] ^ a[i + 1][0];
			mn[1] = i;
		}
	}

	cout << a[mn[1]][1] + 1 << ' ' << a[mn[1] + 1][1] + 1 << ' ' << (((1 << k) - 1) ^ a[mn[1]][0]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}