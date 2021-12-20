#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int states[MAXN];
int states_beg[MAXN];
vector<int> adj[MAXN];

int dfs(int cur, int parent) {
    for (int node : adj[cur]) {
        if (node == parent) continue;
        states[cur]+= 12 - dfs(node, cur);
        states[cur]%= 12;
    }
    return states[cur];
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> states_beg[i];
        if (states_beg[i] == 12) states_beg[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) states[j] = states_beg[j];
        dfs(i, -1);
        if (states[i] == 0 || states[i] == 1) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}