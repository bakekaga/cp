#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

ll adj[MAXN][MAXN];
int vis[MAXN];
int cnt, n;
pair<ll, ll> vertices[MAXN];

void dfs(int cur, ll val) {
	vis[cur]++;
	cnt++;
	for (int i = 0; i < n; i++) 
		if (!vis[i] && adj[cur][i] <= val) dfs(i, val);
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		vertices[i] = {a, b};
	}
	
	ll lo = 1, hi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adj[i][j] = (vertices[j].second - vertices[i].second) * (vertices[j].second - vertices[i].second) + (vertices[j].first - vertices[i].first) * (vertices[j].first - vertices[i].first);
			hi = max(hi, adj[i][j]);
		}
	}
	
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		memset(vis, 0, sizeof vis);
		cnt = 0;
		dfs(0, mid);
		if (cnt < n) lo = mid + 1;
		else hi = mid - 1;
	}
	
	cout << lo << '\n';
	return 0;
}
