#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

vector<int> adj[MAXN];
int dp[MAXN][2];

void dfs(int cur, int prev) {
    int best1 = adj[cur][0], best2;
    for (int node : adj[cur]) {
        if (node != prev) {
            dfs(node, cur);
            if (dp[node][0] >= dp[best1][0]) {
                dp[cur][0] = dp[node][0] + 1;
                swap(best1, best2);
                best1 = node;
            }
        }
    }
    dp[cur][1] = best1 + best2 + 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d1 = 0; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i][1]);
    cout << ans << '\n';
}