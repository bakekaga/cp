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

void solve() {
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll cur = accumulate(arr.begin(), arr.begin() + n / 2 + 1, 0LL);
	ll bmn = cur;
	for (int i = n / 2 + 1; i < n; i++) {
		cur += arr[i] - arr[i - (n / 2 + 1)];
		bmn = min(bmn, cur);
	}
	cout << bmn << ' ' << accumulate(arr.begin(), arr.end(), 0LL) - bmn << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}