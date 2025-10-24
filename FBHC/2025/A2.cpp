#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
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

int main() {
	freopen("A2.txt", "r", stdin);
	freopen("A2out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int lo = 1, hi = *max_element(a.begin(), a.end());
		vector<bool> vis(n);
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			fill(vis.begin(), vis.end(), false);
			queue<int> nxt;
			for (int i = 0; i < n; i++) {
				if (!vis[i] && a[i] <= mid) {
					nxt.push(i);
					while (!nxt.empty()) {
						int cur = nxt.front();
						nxt.pop();
						vis[cur] = true;
						if (cur && !vis[cur - 1] && abs(a[cur] - a[cur - 1]) <= mid) {
							nxt.push(cur - 1);
						}
						if (cur < n - 1 && !vis[cur + 1] && abs(a[cur] - a[cur + 1]) <= mid) {
							nxt.push(cur + 1);
						}
					}
				}
			}

			if (find(vis.begin(), vis.end(), false) == vis.end()) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		cout << "Case #" << tt << ": " << lo << '\n';
	}
}