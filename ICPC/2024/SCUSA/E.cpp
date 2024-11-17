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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 3; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<array<int, 2>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    int treeId = 0;
    vector<bool> globalVis(n + 1);
    array<int, 3> diam;

    vector<int> treeContaining(n + 1, -1);
    int maxDist = -1, furthest = -1;
    function<void(int, int, int)> dfs = [&](int cur, int prev, int depth) {
        globalVis[cur] = true;
        treeContaining[cur] = treeId;
        if (maxDist < depth) {
            furthest = cur;
            maxDist = depth;
        }
        for (int nbr : adj[cur]) {
			if (nbr != prev)
	            dfs(nbr, cur, depth + 1);
        }
    };

    vector<int> furthestDist(n + 1);
    function<void(int, int, int)> dfs2 = [&](int cur, int prev, int depth) {
        furthestDist[cur] = max(furthestDist[cur], depth);
        for (int nbr : adj[cur]) {
			if (nbr != prev)
	            dfs2(nbr, cur, depth + 1);
        }
    };


    for (int i = 1; i <= n; i++) {
        if (!globalVis[i]) {
            maxDist = -1;
            dfs(i, -1, 1);
            int oneEnd = furthest;
            
            maxDist = -1;
            dfs(oneEnd, -1, 1);
            int otherEnd = furthest;
            
            dfs2(oneEnd, -1, 1);
            dfs2(otherEnd, -1, 1);
            diam[treeId] = furthestDist[oneEnd];
            treeId++;
        }
    }

    for (array<int, 2> &query : queries) {
        int tree1 = treeContaining[query[0]];
        int tree2 = treeContaining[query[1]];
        int dist1 = furthestDist[query[0]];
        int dist2 = furthestDist[query[1]];
        assert(tree1 != tree2);
        for (int id = 0; id < 3; id++) {
            if (id != tree1 && id != tree2) {
                cout << diam[id] + dist1 + dist2 << '\n';
            }
        }
    }
    return 0;
}