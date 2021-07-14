#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define MAXN 100005
#define pb push_back
#define sz(x) int(x.size())
 
using namespace std;
 
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	// alternatively, cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

ll cows[MAXN];
pair<ll, ll> shops[MAXN];
ll rent[MAXN];
ll shopsgain[MAXN];
ll rentgain[MAXN];

bool cmp (pair <ll, ll> a, pair<ll, ll> b) {
	return a.first > b.first;
}

int main() {
	setIO("rental");
	int n, m, r; cin >> n >> m >> r;

	for (int i = 0; i < n; i++) cin >> cows[i];
	for (int i = 0; i < m; i++) cin >> shops[i].second >> shops[i].first; 
	for (int i = 0; i < r; i++) cin >> rent[i];
	sort(cows, cows + n, greater<ll>());
	sort(shops, shops + m, cmp);
	sort(rent, rent + r, greater<ll>());

	// calculate total profit from selling milk from the
	// first i cows that can produce the most with greedy
	int j = 0;
	for (int i = 0; i < n; i++) {
		ll curr = cows[i];
		shopsgain[i + 1] = shopsgain[i];
		while (j < m && curr > 0) {
			ll amt = min(shops[j].second, curr);
			curr-= amt;
			shopsgain[i + 1]+= shops[j].first * amt;
			shops[j].second-= amt;
			if (shops[j].second == 0) j++;
		}
	}

	// calculate total profit from renting the first i cows
	// that produce the least milk; then, add to shopgains[n-i]
	// to get total profit from every possible arrangement
	// and find the maximum across all total profits
	ll ret = shopsgain[n];
	for (int i = 1; i <= n; i++) {
		rentgain[i] = rent[i - 1] + rentgain[i - 1];
		ret = max(ret, rentgain[i] + shopsgain[n - i]);
	}
	cout << ret << '\n';
}
