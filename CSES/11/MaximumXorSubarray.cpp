#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb pusv_back

using namespace std;

using ll = long long;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

struct Trie {
    struct Node {
        array<int, 2> nxt;
    };

    vector<Node> t;
    Trie() : t(1) {}

    void insert(int x) {
        int cur_idx = 0;
        for (int i = 31; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (t[cur_idx].nxt[b] == 0) {
                t[cur_idx].nxt[b] = sz(t);
                t.emplace_back();
            }
            cur_idx = t[cur_idx].nxt[b];
        }
    }

	int query(int x) {
		int cur_idx = 0;
		int res = 0;
		for (int i = 31; i >= 0; i--) {
			int b = (x >> i) & 1;
			if (t[cur_idx].nxt[b ^ 1] > 0) {
				res |= (1 << i);
				b ^= 1;
			}
			cur_idx = t[cur_idx].nxt[b];
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
	inclusive_scan(a.begin(), a.end(), psums.begin() + 1, bit_xor<int>{}, 0);
	
	Trie tr;
	int mx = 0;
	for (int i = 0; i <= n; i++) {
		tr.insert(psums[i]);
		mx = max(mx, tr.query(psums[i]));
	}
	cout << mx << '\n';
}