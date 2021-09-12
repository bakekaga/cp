#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".txt").c_str(), "w", stdout);
    }
}

int main() {
    setIO("A2");
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        string str; int k; cin >> str >> k;
        vector<vector<int>> adj(26), dist(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < k; i++) {
        	string s; cin >> s;
            adj[s[0] - 'A'].pb(s[1] - 'A');
        }

        for (int i = 0; i < 26; i++) {
            queue<int> bfs;
            bfs.push(i);
            dist[i][i] = 0;
            while (!bfs.empty()) {
                int cur = bfs.front(); bfs.pop();
                for (auto node : adj[cur]) {
                    if (dist[i][node] == INT_MAX) {
                        bfs.push(node);
                        dist[i][node] = dist[i][cur] + 1;
                    }
                }
            }
        }
        
        int best = INT_MAX;
        for (int i = 0; i < 26; i++) {
            int cur = 0;
            for (int j = 0; j < sz(str); j++) {
                if (dist[str[j] - 'A'][i] == INT_MAX) {
                    cur = best;
                    break;
                }
                cur+= dist[str[j] - 'A'][i];
            }
            best = min(best, cur);
        }
        cout << "Case #" << tt << ": " << (best == INT_MAX ? -1 : best) << '\n';
    }
}