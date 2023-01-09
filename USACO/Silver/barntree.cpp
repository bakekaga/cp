#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

vector<int> adj[MAXN];
ll h[MAXN], avg;
int fin[MAXN];
ll subtree_tot[MAXN];
vector<tuple<int, int, ll>> orders;

void countSum(int par = 0, int cur = 1) {
	subtree_tot[cur] = h[cur] - avg;
	for (int child : adj[cur]) {
		if (child != par) {
			countSum(cur, child);
			subtree_tot[cur]+= subtree_tot[child];
		}
	}
}

void distributeBales(int par = 0, int cur = 1) {
	for (int child : adj[cur]) {
		if (child != par) {
			if (subtree_tot[child] >= 0) distributeBales(cur, child);
			if (subtree_tot[child] > 0) {
				orders.pb({child, cur, subtree_tot[child]});
			}
		}
	}

	for (int child : adj[cur]) {
		if (child != par) {
			if (subtree_tot[child] < 0) {
				orders.pb({cur, child, -subtree_tot[child]});
				distributeBales(cur, child);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		avg+= h[i];
	}
	avg/= n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	countSum();
	distributeBales();

	cout << sz(orders) << '\n';
	for (auto tup : orders) {
		cout << get<0>(tup) << ' ' << get<1>(tup) << ' ' << get<2>(tup) << '\n';
	}
	return 0;
}