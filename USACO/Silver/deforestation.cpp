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
	int n, k;
	cin >> n >> k;
	vector<array<int, 4>> events;
	vector<int> trees(n);
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		events.push_back({trees[i], 0, 0, 0});
	}
	sort(trees.begin(), trees.end());

	for (int i = 0; i < k; i++) {
		int l, r, t;
		cin >> l >> r >> t;
		int cnt = upper_bound(trees.begin(), trees.end(), r) - lower_bound(trees.begin(), trees.end(), l);
		events.push_back({l, -1, r, cnt - t});
	}
	sort(events.begin(), events.end());

	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
	int ans = 0;
	for (auto &[l, isTree, r, extra] : events) {
		if (isTree == -1) {
			pq.push({ans + extra, r});
		}
		else {
			while (!pq.empty() && pq.top()[1] < l) {
				pq.pop();
			}
			if (pq.empty() || pq.top()[0] > ans) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}