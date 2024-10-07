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
	double mn = INF;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if ((x1 < 0 && x2 > 0) || (x2 < 0 && x1 > 0)) {
			double intercept = y1 - x1 * (y2 - y1 + 0.0) / (x2 - x1);
			if (intercept > 0) {
				mn = min(mn, intercept);
			}
		}
	}
	cout << ((mn < 200) ? mn : -1.0) << '\n';
	return 0;
}