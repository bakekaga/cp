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
	int n;
	cin >> n;
	vector<int> found(2 * n);
	vector<int> cur{1};
	for (int i = 2; i <= 2 * n; i++) {
		cur.push_back(i);
		cout << "? " << cur.size() << " ";
		for (int val : cur) {
			cout << val << " ";
		}
		cout << endl;
		int ans;
		cin >> ans;
		if (ans) {
			found[i - 1] = ans;
			cur.pop_back();
		}
	}
	cur.clear();
	for (int i = 2 * n; i >= 1; i--) {
		cur.push_back(i);
		if (found[i - 1]) continue;
		cout << "? " << cur.size() << " ";
		for (int val : cur) {
			cout << val << " ";
		}
		cout << endl;
		int ans;
		cin >> ans;
		if (ans) {
			found[i - 1] = ans;
			cur.pop_back();
		}
	}
	cout << "! ";
	for (int val : found) {
		cout << val << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
