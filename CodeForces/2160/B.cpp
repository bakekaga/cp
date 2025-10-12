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
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

void solve() {
	int n;
    cin >> n;
	vector<ll> b(n);
    vector<int> a(n);
	int cur_lim = 1;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (i > 0) {
			ll diff = b[i] - b[i - 1];
			if (diff == i + 1) {
				cout << cur_lim << ' ';
                a[i] = cur_lim;
				cur_lim++;
			}
			else {
				int possible = a[i - diff];
				cout << possible << ' ';
                a[i] = possible;
			}
		}
		else {
			cout << 1 << ' ';
			cur_lim++;
            a[0] = 1;
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}