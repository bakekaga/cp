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
	string s;
	cin >> s;
	array<ll, 3> cur{}, cost{}, req{};
	for (char i : s) {
		if (i == 'B') {
			req[0]++;
		}
		else if (i == 'S') {
			req[1]++;
		}
		else if (i == 'C') {
			req[2]++;
		}
	}
	ll r;
	cin >> cur[0] >> cur[1] >> cur[2] >> cost[0] >> cost[1] >> cost[2] >> r;
	ll lo = 1, hi = r + *max_element(cur.begin(), cur.end());
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2, tot = 0;
		for (int tt = 0; tt < 3; tt++) {
			tot += max(req[tt] * mid - cur[tt], 0LL) * cost[tt];
		}
		if (tot > r) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << hi << '\n';
	return 0;
}