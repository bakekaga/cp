#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

int main() {
	freopen("A1.txt", "r", stdin);
	freopen("A1out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int maxDiff = 0;
		for (int i = 1; i < n; i++) {
			maxDiff = max(maxDiff, abs(a[i] - a[i - 1]));
		}
		cout << "Case #" << tt << ": " << maxDiff << '\n';
	}
}