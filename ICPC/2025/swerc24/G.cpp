#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll r;
	int n;
	cin >> r >> n;
	vector<ll> moves(n);
	ll start_zero = 0, start_r = r;
	for (int i = 0; i < n; i++) {
		cin >> moves[i];
		start_r += moves[i];
		if (start_r > r) {
			start_r = r;
		} else if (start_r < 0) {
			start_r = 0;
		}
		start_zero += moves[i];
		if (start_zero > r) {
			start_zero = r;
		} else if (start_zero < 0) {
			start_zero = 0;
		}
	}
	cout << (start_r == start_zero ? to_string(start_r) : "uncertain") << "\n";
}