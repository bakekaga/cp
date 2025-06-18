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
	array<int, 26> nxt;
	bool on;
	Node() : nxt{}, on{} { }
};

int add(int a, int b) {
    a += b;
    return (a >= MOD ? a - MOD : a);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	int k;
	cin >> s >> k;
    vector<Node> trie(1);
	for (int i = 0; i < k; i++) {
		string dict_entry;
		cin >> dict_entry;
		int cur_idx = 0;
        for (char ch : dict_entry) {
            int c = ch - 'a';
            if (trie[cur_idx].nxt[c] == 0) {
                trie[cur_idx].nxt[c] = sz(trie);
                trie.emplace_back();
            }
            cur_idx = trie[cur_idx].nxt[c];
        }
		trie[cur_idx].on = true;
	}

	int n = s.size();
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int cur_idx = 0;
		for (int j = i; j < n; j++) {
			cur_idx = trie[cur_idx].nxt[s[j] - 'a'];
			if (cur_idx == 0) break;
			if (trie[cur_idx].on) {
				dp[j + 1] = add(dp[j + 1], dp[i]);
			}
		}
	}
	cout << dp[n] << '\n';
	return 0;
}