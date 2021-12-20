#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int n, m, k; cin >> n >> m >> k;
	vector<int> map(n + 1);
	// after m reversals, i goes to map[i]
	vector<vector<int>> cycles;
	vector<pair<int, int>> pos(n + 1);
	// pos[i].first is the index of the cycle containing i,
	// pos[i].second is index of i inside that cycle
	vector<bool> found(n + 1);
	// found[i] is true if i is already in a cycle
	for (int i = 1; i <= n; i++) map[i] = i;
	vector<int> arr(map);

	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		reverse(map.begin() + l, map.begin() + r + 1);
	}

	for (int i = 1; i <= n; i++) {
		if (found[i]) continue;
		cycles.pb(vector<int>()); // new cycle created
		do {
			cycles[sz(cycles) - 1].pb(arr[i]);
			pos[arr[i]] = mp(sz(cycles) - 1, sz(cycles[sz(cycles) - 1]) - 1);
			found[arr[i]] = true;
			arr[i] = map[arr[i]];
		}
		while (arr[i] != i);
	}
	
	for (int i = 1; i <= n; i++) {
		int mod = (pos[i].second + k) % sz(cycles[pos[i].first]);
		cout << cycles[pos[i].first][mod] << '\n';
	}
}