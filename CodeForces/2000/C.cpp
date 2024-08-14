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
	int n, m;
	cin >> n;
	vector<int> p(n), sizes(n, 1);
	iota(p.begin(), p.end(), 0);
	function<int(int)> get = [&](int u) {
		if (u == p[u]) return u;
		return p[u] = get(p[u]);
	};
	function<void(int, int)> unite = [&](int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
			if (sizes[a] < sizes[b]) swap(a, b);
			p[b] = a;
			sizes[a] += sizes[b];
		}
	};
	map<ll, vector<int>> a;
	for (int i = 0; i < n; i++) {
		ll cur;
		cin >> cur;
		a[cur].pb(i);
	}
	for (auto &[k, v] : a) {
		for (int i = 1; i < sz(v); i++) {
			unite(v[0], v[i]);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string out = "YES\n", s;
		cin >> s;
		if (sz(s) != n) {
			out = "NO\n";
		}
		else {
			map<char, int> freq;
			for (char c : s) {
				freq[c]++;
			}
			for (int j = 0; j < sz(s); j++) {
				if (freq[s[j]] != sizes[get(j)] || s[j] != s[get(j)]) {
					out = "NO\n";
					break;
				}
			}
		}
		cout << out;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}