#include <bits/stdc++.h>
using namespace std;

array<int, 26> p;
array<int, 26> sizes;

int get(int v) {
	if (v == p[v]) {
		return v;
	}
	return (p[v] = get(p[v]));
}

void unite(int u, int v) {
	u = get(u), v = get(v);
	if (u == v) {
		return;
	}
	if (sizes[u] < sizes[v]) {
		swap(u, v);
	}
	sizes[u] += sizes[v];
	p[v] = u;
}

void solve() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if (s1.size() != s2.size()) {
		cout << "NO\n";
	} else if (s1.size() != s3.size()) {
		cout << "YES\n";
	} else {
		iota(p.begin(), p.end(), 0);
		fill(sizes.begin(), sizes.end(), 1);
		
		int n = (int)s1.size();
		for (int i = 0; i < n; i++) {
			unite(s1[i] - 'a', s2[i] - 'a');
		}
		for (int i = 0; i < n; i++) {
			if (get(s3[i] - 'a') != get(s1[i] - 'a')) {
				cout << "YES\n";
				return;
			}
		}
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
