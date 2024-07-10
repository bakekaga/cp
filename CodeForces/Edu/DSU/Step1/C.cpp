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

vector<int> p, sz, pts, sub;

int get(int v) {
	if (v == p[v]) return v;
	return get(p[v]);
}

void unite(int a, int b) {
	a = get(a), b = get(b);
	if (a != b) {
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		p[b] = a;
		sz[a] += sz[b];
		sub[b] = -pts[a];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	p = pts = sub = vector<int>(n + 1);
	sz = vector<int>(n + 1, 1);
	iota(p.begin(), p.end(), 0);
	while (m--) {
		string s;
		cin >> s;
		if (s == "join") {
			int x, y;
			cin >> x >> y;
			unite(x, y);
		}
		else if (s == "add") {
			int x, v;
			cin >> x >> v;
			x = get(x);
			pts[x] += v;
		}
		else {
			int x;
			cin >> x;
			int tot = 0;
			while (x != p[x]) {
				tot += pts[x] + sub[x];
				x = p[x];
			}
			tot += pts[x] + sub[x];
			cout << tot << '\n';
		}
	}
	return 0;
} 