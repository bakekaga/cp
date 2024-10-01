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
	int n, R; cin >> n >> R;
	set<array<int, 2>> covered;
	for (int i = 0; i < n; i++) {
		int r, x, y;
		cin >> r >> x >> y;
		for (int j = x - r; j <= x + r; j++) {
			for (int k = y - r; k <= y + r; k++) {
				bool valid = (abs(x - j) * abs(x - j) + abs(y - k) * abs(y - k) <= r * r);
				valid &= (j * j + k * k <= R * R);
				if (valid) {
					covered.insert({j, k});
				}
			}
		}
	}
	cout << covered.size() << '\n';
	return 0;
}