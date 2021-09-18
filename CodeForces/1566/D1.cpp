#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
 
using namespace __gnu_pbds;
 
void solve() {
	int n, m, sum = 0; cin >> n >> m;
	ordered_set used;
	for (int i = 0; i < n * m; i++) {
		int x; cin >> x;
		sum+= used.order_of_key(mp(x, -i));
		used.insert(mp(x, -i));
	}
	cout << sum << '\n';
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}