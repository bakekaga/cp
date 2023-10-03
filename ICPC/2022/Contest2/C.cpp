#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 11;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int n;
vector<int> res;

int go(int ind, vector<int> cur) {
	if (ind == sz(res)) {
		int ret = 0;
		for (auto x : cur) if (x) ret++;
		return ret;
	}
	// cout << ind << ": ";
	// for (int i : cur) cout << i << ' ';
	// cout << '\n';
	int ans1 = INF, ans2 = INF;
	if (res[ind] > 0 && cur[res[ind] - 1]) {
		cur[res[ind] - 1]--;
		ans1 = go(ind + 1, cur);
	}
	if (res[ind] < n - 1 && cur[res[ind] - 1]) {
		cur[res[ind] + 1]--;
		ans2 = go(ind + 1, cur);
	}
	return min(ans1, min(ans2, go(ind + 1, cur)));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int s, r; cin >> n >> s >> r;
	vector<int> dmg(n);
	for (int i = 0; i < s; i++) {
		int x; cin >> x;
		dmg[x - 1]++;
	}
	for (int i = 0; i < r; i++) {
		int x; cin >> x;
		x--;
		if (dmg[x]) dmg[x]--;
		else res.pb(x);
	}

	cout << go(0, dmg) << '\n';
	return 0;
}