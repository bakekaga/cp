#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

void solve() {
	unsigned int n;
	cin >> n;
	bitset<32> bs(n);
	int end = 32 - countl_zero(n);
	int start = countr_zero(n);
    for (int i = 0; i < (end - start) / 2; i++) {
		if (bs[start + i] != bs[end - 1 - i]) {
			cout << "NO\n";
            return;
		}
	}
    if (((end - start) & 1) && bs[(end + start) / 2]) {
		cout << "NO\n";
		return;
    }
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}