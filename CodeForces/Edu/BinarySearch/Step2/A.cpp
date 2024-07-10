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
	ll w, h, n;
	cin >> w >> h >> n;
	ll l = 1, r = 1;
	while ((r / w) * (r / h) < n) {
		r <<= 1;
	}
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if ((mid / w) * (mid / h) >= n) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
	return 0;
}