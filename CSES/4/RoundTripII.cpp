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

vector<int> adj[MAXN];
bool vis[MAXN];
int ind[MAXN];
vector<int> ord;
 
void dfs(int cur) {
	vis[cur] = true;
	for (int x : adj[cur]) {
		if (!vis[x]) dfs(x);
	}
	ord.pb(cur);
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
	}
 
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);
	}
	reverse(ord.begin(), ord.end());
	
	for (int i = 0; i < n; i++) {
		ind[ord[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int x : adj[i]) {
			if (ind[x] <= ind[i]) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << ord[i] << '\n';
	}
	
	return 0;
}