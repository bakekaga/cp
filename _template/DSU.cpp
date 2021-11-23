// DISJOINT SET UNION
#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

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
