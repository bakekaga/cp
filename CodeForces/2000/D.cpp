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
	vector<ll> a(n), psums(n + 1), l, r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		psums[i + 1] = psums[i] + a[i];
	}
	string s;
	cin >> s;
	ll tot = 0;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == 'L') l.pb(i);
		else r.pb(i); 
	}
	reverse(r.begin(), r.end());
	for (int i = 0; i < min(sz(l), sz(r)); i++) {
		if (l[i] < r[i])
			tot += psums[r[i] + 1] - psums[l[i]];
	}
	cout << tot << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}