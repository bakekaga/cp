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
    for (int node : adj[cur]) {
        if (node != prev) {
            dfs(node, cur);
            dp[cur][1]+= max(dp[node][1], dp[node][0]);
        }
    }
    for (int node : adj[cur]) {
        if (node != prev) {
            dp[cur][0] = max(dp[cur][0],
            (1 + dp[node][1]) + (dp[cur][1] - max(dp[node][1], dp[node][0])));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}