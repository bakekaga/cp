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
	vector<ll> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
 
	auto process = [&](int l, int r) {
		unordered_map<ll, ll> cnt;
		int len = r - l;
		cnt.reserve(1 << len);
		for (int i = 0; i < (1 << len); i++) {
			ll tot = 0;
			for (int j = 0; j < len; j++) {
				if (i & (1 << j)) {
					tot += t[l + j];
				}
			}
			cnt[tot]++;
		}
		return cnt;
	};
 
	unordered_map<ll, ll> leftCnt = process(0, n / 2);
	unordered_map<ll, ll> rightCnt = process(n / 2, n);
 
	ll res = 0;
	for (auto &[key, val] : leftCnt) {
		auto node = rightCnt.find(x - key);
		if (node != rightCnt.end()) {
			res += val * node->second;
		}
	}
 
	cout << res << '\n';
	return 0;
}