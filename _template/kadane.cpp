#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

ll kadane(int n, bool empty) {
	vector<ll> arr(n);
	ll best = INT_MIN, sum = 0;
	for (int k = 0; k < n; k++) {
		if (empty) { // empty subarray allowed (ans is nonnegative)
			sum = max(0LL, sum + arr[k]);
		}
		else { // empty subarray not allowed
			sum = max(arr[k], sum + arr[k]);
		}
		best = max(best, sum);
	}
	return best;
}
