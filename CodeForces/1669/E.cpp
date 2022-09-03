#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define vout(x, n) for(int i = 0; i < n; i++) cout << x[i] << ' '; cout << '\n';

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

void solve() {
	int n; cin >> n;
	vector<string> a(n);
	vector<ll> fcnt(11), scnt(11);
	vector<vector<ll>> cnt(11, vector<ll>(11));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i][0] - 'a'][a[i][1] - 'a']++;
		fcnt[a[i][0] - 'a']++;
		scnt[a[i][1] - 'a']++;
	}
	ll tot = 0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			tot+= cnt[i][j] * (fcnt[i] + scnt[j] - 2 * cnt[i][j]);
		}
	}
	cout << tot / 2LL << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}