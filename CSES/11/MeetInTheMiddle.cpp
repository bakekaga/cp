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
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(n / 2), b(n - n / 2);
	for (int i = 0; i < n / 2; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - n / 2; i++) {
		cin >> b[i];
	}

	unordered_map<ll, ll> cnt;
	cnt.reserve(1 << sz(a));
	for (int j = 0; j < (1 << sz(a)); j++) {
		ll tot = 0;
		for (int k = 0; k < sz(a); k++) {
			if (j & (1 << k)) {
				tot += a[k];
				if (tot > x) {
					break;
				}
			}
		}
		if (tot <= x) {
			cnt[tot]++;
		}
	}

	ll res = 0;
	for (int j = 0; j < (1 << sz(b)); j++) {
		ll tot = 0;
		for (int k = 0; k < sz(b); k++) {
			if (j & (1 << k)) {
				tot += b[k];
				if (tot > x) {
					break;
				}
			}
		}
		if (tot <= x) {
			res += cnt[x - tot];
		}
	}

	cout << res << '\n';
	return 0;
}