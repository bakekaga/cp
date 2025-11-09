#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> m;
	map<int, int> freq;
	rep(i, 0, m) {
		int x;
		cin >> x;
		freq[x]++;
	}
	int mx = 0;
	for (auto& [dist, cnt] : freq) {
		if (dist & 1) {
			mx = max(mx, 1 + (dist + 1) / 2 + (cnt - 1) / 2);
		} else {
			mx = max(mx, 1 + dist / 2 + cnt / 2);
		}
	}
	cout << mx << '\n';
	return 0;
}