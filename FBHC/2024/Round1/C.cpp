#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
	freopen("C.txt", "r", stdin);
	freopen("Cout.txt", "w", stdout);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		ll w, g, l; cin >> w >> g >> l;
		cout << "Case #" << tt << ": " << (w - g) % MOD * ((2 * l + 1) % MOD) % MOD << '\n';
	}
}