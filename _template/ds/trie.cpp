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

// bitwise Trie (for bitwise xor problems)
template<int SZ = 2>
struct Trie {
    struct Node {
        vector<int> nxt;
		bool on;
        Node() : nxt(SZ), on{} { }
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
		t[cur_idx].on = true;
    }
};

// Trie (for string problems)
template<int SZ = 26>
struct Trie {
    struct Node {
        vector<int> nxt;
		bool on;
        Node() : nxt(SZ), on{} { }
    };

    vector<Node> t;
    Trie() : t(1) {}
    
	int conv(int c) { return c - 'a'; }
    void insert(const string &s) {
        int cur_idx = 0;
        for (char ch : s) {
            int c = conv(ch);
            if (t[cur_idx].nxt[c] == 0) {
                t[cur_idx].nxt[c] = sz(t);
                t.emplace_back();
            }
            cur_idx = t[cur_idx].nxt[c];
        }
		t[cur_idx].on = true;
    }
    bool contains(const string &s) {
        int cur_idx = 0;
        for (char ch : s) {
            int c = conv(ch);
            cur_idx = t[cur_idx].nxt[c];
            if (cur_idx == 0) return false;
        }
        return t[cur_idx].on;
    }
	// obtain all strings in lexicographical order with a preorder traversal
	vector<string> trav() {
        vector<string> out;
        stack<pair<int, string>> dfs;
        dfs.push({t[0], ""});
        while (!dfs.empty()) {
            int cur_idx = dfs.top().first;
            string val = dfs.top().second;
            if (val != "") {
                out.push_back(val);
			}
            dfs.pop();
            for (int i = SZ - 1; i >= 0; i--) {
                if (t[cur_idx].nxt[i] != 0) {
                    dfs.push({t[cur_idx].nxt[i], val + (char) (i + 'a')});
                }
            }
        }
        return out;
    }
};
