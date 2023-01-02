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
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	int n, t; cin >> n >> t;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int dur = 0;
		priority_queue<int> cur;
		for (int i = 0; i < mid; i++) {
			cur.push(-arr[i]);
		}
		for (int i = mid; !cur.empty(); i++) {
			dur = -cur.top();
			cur.pop();
			if (i < n) cur.push(-(arr[i] + dur));
		}
		if (dur <= t) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << lo << '\n';
	return 0;
}