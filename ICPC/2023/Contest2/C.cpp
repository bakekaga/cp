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
	int p; cin >> p;
	for (int tt = 0; tt < p; tt++) {
		int qq; int x, y;
		cin >> qq >> x >> y;
		cout << qq << ' ';
		if (x < y) {
			cout << 2 << ' ' << x << ' ' << y << '\n';
		}
		else if (y >= 4) {
			cout << 6 << " 1 2 3 " << 2 - y + (x + 3) << ' ' << x + 2 << ' ' << x + 3 << '\n';
		}
		else {
			cout << "NO PATH\n";
		}
	}
}