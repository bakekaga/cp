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
     
    int n;
    vector<int> adj[MAXN];
    int vis[MAXN];
    vector<int> ord;
     
    void dfs(int cur) {
    	vis[cur]++;
    	for (int x : adj[cur]) {
    		if (!vis[x]) dfs(x);
    	}
    	ord.pb(cur);
    }
     
    void solve() {
    	int k;
    	cin >> n >> k;
    	vector<ll> c(n + 1), out(n + 1, INFLL), free(n + 1);
    	fill(vis, vis + n + 1, 0);
    	fill(adj, adj + n + 1, vector<int>());
    	ord.clear();
    	
    	for (int i = 1; i <= n; i++) cin >> c[i];
    	for (int i = 0; i < k; i++) {
    		int x;
    		cin >> x;
    		free[x]++;
    	}
    	for (int i = 1; i <= n; i++) {
    		int m, e;
    		cin >> m;
    		for (int j = 0; j < m; j++) {
    			cin >> e;
    			adj[e].pb(i);
    		}
    	}
    	
    	for (int i = 1; i <= n; i++) {
    		if (!vis[i]) dfs(i);
    	}
    	reverse(ord.begin(), ord.end());
    	
    	for (int x : ord) {
    		out[x] = (free[x] ? 0 : min(out[x], c[x]));
    		for (int nbr : adj[x]) {
    			if (out[nbr] == INFLL) out[nbr] = out[x];
    			else out[nbr]+= out[x];
    		}
    	}
    	for (int i = 1; i <= n; i++) cout << out[i] << ' ';
    	cout << '\n';
    }
     
    int main() {
    	ios_base::sync_with_stdio(0); cin.tie(0);
    	int t; cin >> t;
    	while (t--) {
    		solve();
    	}
    	return 0;
    }