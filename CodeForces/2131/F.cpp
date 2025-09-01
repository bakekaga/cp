#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 63;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

vector<int> values(MAXN);
vector<int> numOps(MAXN);

void solve() {
	int n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	values[1] = 1;
	numOps[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		values[i] = i;
		numOps[i] = 1;
		for (int j = 1; j < i; j++) {
			values[i] = values[i] * values[i - 1] % MOD;
			numOps[i] += numOps[j]; 
		}
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
