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

struct Node {
	array<int, 2> nxt;
	int id;
	Node() : nxt{}, id{} {}
};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<Node> trie(1);
	array<int, 3> best = {1, 2, 0};
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) {
			int cur_idx = 0;
			int x = 0;
			for (int j = k - 1; j >= 0; j--) {
				int b = (a[i] >> j) & 1;
				if (trie[cur_idx].nxt[b] > 0) {
					x |= ((1 - b) << j);
				}
				else {
					b ^= 1;
				}
				cur_idx = trie[cur_idx].nxt[b];
			}
			if (((a[i] ^ x) & (a[trie[cur_idx].id] ^ x)) > ((a[best[0]] ^ best[2]) & (a[best[1]] ^ best[2]))) {
				best = {trie[cur_idx].id, i, x};
			}
		}
		// insert new node
		int cur_idx = 0;
		for (int j = k - 1; j >= 0; j--) {
			int b = (a[i] >> j) & 1;
			if (trie[cur_idx].nxt[b] == 0) {
				trie[cur_idx].nxt[b] = sz(trie);
				trie.emplace_back();
			}
			cur_idx = trie[cur_idx].nxt[b];
		}
		trie[cur_idx].id = i;
	}
	for (int val : best) {
		cout << val << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}