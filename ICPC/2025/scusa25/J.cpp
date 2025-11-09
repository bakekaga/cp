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
	int n;
	cin >> n;
	bool isodd = false;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x & 1) {
			isodd = true;
		}
		s.insert(x);
	}
	if (s.size() == 2 and s.count(0) and s.count(5)) {
		cout << n << "\n";
	} else if (s.size() == 1 and s.count(5)) {
		cout << n << '\n';
	} else {
		cout << (isodd ? 1 : n) << "\n";
	}
	return 0;
}