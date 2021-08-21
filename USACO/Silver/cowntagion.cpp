#include <bits/stdc++.h>
#define MAXN 100000
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

vector<int> farms[MAXN];

int res = -1;

void dfs(int n, int prev) {
    res++;
    if (farms[n].size() == 1) return;
    int daysdoubling;
    if (n == 1) {
        daysdoubling = (int) log2(farms[n].size()) + 1;    
    }
    else {
        if (floor(log2(farms[n].size())) == ceil(log2(farms[n].size()))) daysdoubling = (int) log2(farms[n].size());
        else daysdoubling = (int) log2(farms[n].size()) + 1;
    }
    res += daysdoubling;
    for (int i = 0; i < farms[n].size(); i++) {
        if (farms[n][i] != prev) {
            dfs(farms[n][i], n);
        }
    }
}

int main() {
    setIO();
    int n, a, b; cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        farms[a].pb(b);
        farms[b].pb(a);
    }
    dfs(1, INT_MAX);
    cout << res << '\n';
    return 0;
}