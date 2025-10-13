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
	bool mark, on;
	array<int, 26> nxt;
};

vector<Node> trie;

void insert(string &s) {
	int cur = 0;
	for (char ch : s) {
		int c = ch - 'a';
		if (trie[cur].nxt[c] == 0) {
			trie[cur].nxt[c] = sz(trie);
			trie.emplace_back();
		}
		cur = trie[cur].nxt[c];
	}
	trie[cur].on = true;
}

void dfs(int cur, vector<char> &out) {
	if (trie[cur].on) {
		out.push_back('P');
	}
	int marked_child = -1;
	for (int i = 0; i < 26; i++) {
		if (trie[cur].nxt[i]) {
			if (trie[trie[cur].nxt[i]].mark) {
				marked_child = i;
			}
			else {
				out.push_back('a' + i);
				dfs(trie[cur].nxt[i], out);
			}
		}
	}
	if (marked_child != -1) {
		out.push_back('a' + marked_child);
		dfs(trie[cur].nxt[marked_child], out);
	}
	if (!trie[cur].mark && cur > 0) {
		out.push_back('-');
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	trie.emplace_back();
	vector<string> words(n);
	int mx_ind = 0;
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		insert(words[i]);
		if (sz(words[mx_ind]) < sz(words[i])) {
			mx_ind = i;
		}
	}
	// mark all chars of longest word
	int cur = 0;
	for (char ch : words[mx_ind]) {
		int c = ch - 'a';
		cur = trie[cur].nxt[c];
		trie[cur].mark = true;
	}
	vector<char> out;
	out.reserve(n);
	dfs(0, out);
	cout << sz(out) << '\n';
	for (char ch : out) {
		cout << ch << '\n';
	}
	return 0;
}