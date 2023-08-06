#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb pusv_back

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

template<int SZ = 2>
struct trie {
	struct node {
		vector<int> nxt;
		node() { nxt = vector<int>(SZ, -1); }
	};
	
	vector<node> t;
	int root;

	template<typename ...Args>
	int new_node(Args ...args) {
		t.emplace_back(args...);
		return sz(t) - 1;
	}
	trie() { root = new_node(); }

	void insert(int x) {
		int cur = root;
		for (int i = 31; i >= 0; i--) {
			int b = (x >> i) & 1;
			if (t[cur].nxt[b] == -1) {
				t[cur].nxt[b] = new_node();
			}
			cur = t[cur].nxt[b];
		}
	}

	int query(int x) {
		int cur = root;
		int res = 0;
		for (int i = 31; i >= 0; i--) {
			int b = (x >> i) & 1;
			if (t[cur].nxt[b ^ 1] != -1) {
				res += 1 << i;
				cur = t[cur].nxt[b ^ 1];
			}
			else {
				cur = t[cur].nxt[b];
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), psums(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	inclusive_scan(a.begin(), a.end(), psums.begin() + 1, bit_xor{}, 0);
	
	trie t;
	int mx = 0;
	for (int i = 0; i <= n; i++) {
		t.insert(psums[i]);
		mx = max(mx, t.query(psums[i]));
	}
	cout << mx << '\n';
}