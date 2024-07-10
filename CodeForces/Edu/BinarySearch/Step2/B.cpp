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
	int n, k; cin >> n >> k;
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	double l = (double) n / k, r = *max_element(a.begin(), a.end());
	// for (int tt = 0; tt < 100; tt++) {
	while (l + EPS <= r) {
		double mid = l + (r - l) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += a[i] / mid;
		}
		if (cnt < k) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << setprecision(20) << r << '\n';
	return 0;
}