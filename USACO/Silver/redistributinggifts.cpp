#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 501;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> adj(n + 1), pref(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			int x; cin >> x;
			pref[i][x] = j;
			if (!sz(adj[i]) || adj[i].back() != i) adj[i].pb(x);
		}
		adj[i].pop_back();
	}

	for (int i = 1; i <= n; i++) {
		stack<int> st;
		vector<int> good, vis(n + 1);
		st.push(i);
		while (!st.empty()) {
			int cur = st.top();
			st.pop();
			vis[cur]++;
			for (auto &x : adj[cur]) {
				if (x == i) good.pb(cur);
				if (!vis[x]) st.push(x);
			}
		}
		int best = i;
		for (auto &x : good) {
			if (pref[i][best] < pref[i][x]) best = x;
		}
		cout << best << '\n';
	}
	return 0;
}