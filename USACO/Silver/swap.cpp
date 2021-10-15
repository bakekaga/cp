#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> seq, out;
	for (int i = 0; i <= n; i++) {
		seq.pb(i);
		out.pb(i);
	}
	
	while (m--) {
		int l, r;
		cin >> l >> r; r++;
		reverse(seq.begin() + l, seq.begin() + r);
	}
			
	vector<vector<int>> cyc;
	cyc.pb(vector<int>());
	vector<pair<int, int>> seen(n + 1);
	for (int i = 1; i <= n; i++) {
		if (seen[i].first) continue;
		cyc.pb(vector<int>());
		int cnt = 0;
		do {
			cyc[cyc.size() - 1].pb(seq[out[i]]);
			out[i] = seq[out[i]];
			seen[out[i]] = mp(cyc.size() - 1, cnt);
			cnt++;
		} while (out[i] != i);
	}
	
	for (int i = 1; i <= n; i++) {
		int mod = (int) ((k + seen[i].second) % ((ll) cyc[seen[i].first].size()));
		cout << cyc[seen[i].first][mod] << '\n';
	}
	return 0;
}