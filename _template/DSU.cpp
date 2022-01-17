// DISJOINT SET UNION
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

struct DSU {
	vector<int> e;
	DSU(int N) {
        e = vector<int>(N, -1);
    }

	// get representive component (uses path compression)
	int get(int x) {
        if (e[x] < 0) return x;
        return e[x] = get(e[x]);
    }
	
	bool same_set(int a, int b) {
        return get(a) == get(b);
    }
	
	int size(int x) {
        return -e[get(x)];
    }
	
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x]+= e[y];
		e[y] = x;
		return true;
	}
};
