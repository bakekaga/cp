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
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (k--) {
		int q;
		cin >> q;
		// cout << lower_bound(arr.begin(), arr.end(), q) - arr.begin() + 1 << '\n';
		int lo = 0, hi = n - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (arr[mid] < q) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		cout << lo + 1 << '\n';
	}
	return 0;
}