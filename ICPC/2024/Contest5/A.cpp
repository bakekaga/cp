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
	int n, s; cin >> n >> s;
	vector<ll> width(n);
	for (int i = 0; i < n; i++) {
		cin >> width[i];
	}
	// edge case
	if (n <= 2 || s <= 2) {
		cout << min(s, n) << '\n';
		return 0;
	}

	s -= 2; // always put the biggest 2 at the ends
	sort(width.begin(), width.end());
	
	auto check = [&](int pref) {
		array<vector<ll>, 3> mod;
		for (int i = 0; i < pref; i++) {
			mod[width[i] % 3].push_back(width[i]);
		}
		ll used = accumulate(mod[0].begin(), mod[0].end(), 0LL) / 3;
		int i = 0;
		for (; i < sz(mod[1]) && i < sz(mod[2]); i++) {
			used += (mod[1][i] + mod[2][i]) / 3;
		}
		for (int j = i; j < sz(mod[1]); j++) {
			ll cur = mod[1][j];
			if (j + 1 < sz(mod[1])) {
				cur += mod[1][j + 1];
				j++;
			}
			used += (cur + 2) / 3; // ceil(cur / 3)
		}
		for (int j = i; j < sz(mod[2]); j++) {
			used += (mod[2][j] + 1) / 3;
		}
		return used <= s;
	};

	int lo = 1, hi = n - 2;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << hi + 2 << '\n';
	return 0;
}