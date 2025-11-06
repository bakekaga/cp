#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;

unsigned int pot(unsigned int a, unsigned int b) {
	unsigned int res = 1;
	while (b) {
		if (b & 1u) {
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve() {
	unsigned int a, b = 0;
	cin >> a;
	vector<unsigned int> wtf;
	for (int i = 1; i < 33; i++) {
		unsigned int pref = b & ((1u << i) - 1u);
		unsigned int aux = pot(a, (1u << i) | pref);
		wtf.push_back(b);
		if ((a ^ aux) & (1u << i)) {
			b |= (1u << i);
		}
	}
	set<unsigned int> ans;
	for (unsigned int b : wtf) {
		if (pot(a, b) == (a ^ b)) {
			ans.insert(b);
		}
	}
	cout << ans.size() << " ";
	for (unsigned int b : ans) {
		cout << b << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
