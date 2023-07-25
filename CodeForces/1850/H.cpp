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
     
    void solve() {
    	int n, m;
    	cin >> n >> m;
    	vector<vector<array<int, 2>>> adj(n + 1);
    	for (int i = 0; i < m; i++) {
	    	int a, b, d;
    		cin >> a >> b >> d;
    		adj[a].pb({b, d});
    		adj[b].pb({a, -d});
    	}
		// coords doubles as vis array
    	vector<ll> coords(n + 1, INFLL);
    	for (int i = 1; i <= n; i++) {
			if (coords[i] != INFLL) continue;
			stack<int> dfs;
			dfs.push(i);
			coords[i] = 0;
			while (!dfs.empty()) {
				int cur = dfs.top();
				dfs.pop();
				for (auto nbr : adj[cur]) {
					if (coords[nbr[0]] == INFLL) {
						coords[nbr[0]] = coords[cur] + nbr[1];
						dfs.push(nbr[0]);
					}
					else if (coords[nbr[0]] != coords[cur] + nbr[1]) {
						cout << "NO\n";
						return;
					}
				}
			}
		}
    	cout << "YES\n";
    }
     
    int main() {
    	ios_base::sync_with_stdio(0); cin.tie(0);
    	int t; cin >> t;
    	while (t--) {
    		solve();
    	}
    	return 0;
    }