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
		string ans = "NO\n";
		cin >> q;
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] < q) {
				l = mid + 1;
			}
			else if (arr[mid] > q) {
				r = mid - 1;
			}
			else {
				ans = "YES\n";
				break;
			}
		}
		cout << ans;
	}
	return 0;
}