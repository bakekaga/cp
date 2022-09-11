#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 5e8 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

void solve() {
	int n, sum = 0; cin >> n;
	int ans = n - 1;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum+= arr[i];
	}
	if (sum == 0) {
		cout << 0 << '\n';
		return;
	}
	vector<int> divs;
	for (int i = 1; i * i <= sum; i++) {
		if (sum % i == 0) {
			divs.pb(i);
			divs.pb(sum / i);
		}
	}
	for (int &div : divs) {
		int part = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			part+= arr[i];
			cnt++;
			if (part > div) {
				cnt = n - 1;
				break;
			}
			else if (part == div) {
				part = 0;
				cnt--;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}