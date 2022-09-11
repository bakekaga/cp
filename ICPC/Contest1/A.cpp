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
	int d, r, t; cin >> d >> r >> t;
	for (int i = 3; i <= 1000; i++) {
		int tAge = i, rAge = i + d;
		int tot = tAge * (tAge + 1) + rAge * (rAge + 1);
		if (tot == 2 * (t + r + 9)) {
			cout << r - (rAge * (rAge + 1) / 2 - 6) << '\n';
			break;
		}
	}
	return 0;
}