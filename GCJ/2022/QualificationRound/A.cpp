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

void solve() {
	int r, c; cin >> r >> c;
	cout << "..";
	for (int i = 1; i < c; i++) {
		cout << "+-";
	}
	cout << "+\n..";
	for (int i = 1; i < c; i++) {
		cout << "|.";
	}
	cout << "|\n";
	for (int i = 1; i < r; i++) {
		for (int i = 0; i < c; i++) {
			cout << "+-";
		}
		cout << "+\n";
		for (int i = 0; i < c; i++) {
			cout << "|.";
		}
		cout << "|\n";
	}
	for (int i = 0; i < c; i++) {
		cout << "+-";
	}
	cout << "+\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ":\n";
		solve();
	}
	return 0;
}