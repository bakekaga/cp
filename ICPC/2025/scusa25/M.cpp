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
	int r, c;
	cin >> r >> c;
	if (r == 1) {
		cout << ((c + 2) / 3) << "\n";
	} else if (r == 2) {
		cout << (c + 2) / 2 << "\n";
	} else {
		if (c == 1) {
			cout << 1 << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
	return 0;
}