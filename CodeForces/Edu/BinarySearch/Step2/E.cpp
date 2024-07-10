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
	double c; cin >> c;

	double l = 0, r = c;
	for (int tt = 0; tt < 100; tt++) {
		double x = l + (r - l) / 2;
		if (x * x + sqrt(x) - c >= EPS) {
			r = x;
		}
		else {
			l = x;
		}
	}
	cout << setprecision(20) << l << '\n';
	return 0;
}