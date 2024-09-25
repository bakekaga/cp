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
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	vector<array<int, 2>> val(n);
	for (int i = 0; i < n; i++) {
		if (s1[i] - '1' > 1) {
			val[i][0]++;
		}
		if (s2[i] - '1' > 1) {
			val[i][1]++;
		}
	}
	int curPos = 0;
	for (int i = 0; i < n; i++) {
		if (val[i][curPos]) {
			if (val[i][curPos ^ 1]) {
				curPos ^= 1;
			}
			else {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << (curPos ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		solve();
	}
}