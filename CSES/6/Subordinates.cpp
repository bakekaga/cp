#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

vector<int> adj[MAXN];
int ans[MAXN];

void dfs(int node) {
    ans[node]++;
    for (int child : adj[node]) {
        dfs(child);
        ans[node]+= ans[child];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        adj[x - 1].pb(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] - 1 << ' ';
    }
    return 0;
}