#include <bits/stdc++.h>
#define MAXN 1005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

ll x, y, dp[3][MAXN];
bool found[3][MAXN];
string s;

ll go(int prev, int i) {
    if (i >= sz(s)) return 0;
    if (found[prev][i]) return dp[prev][i];
    found[prev][i] = true;
    ll c = (prev == 1 ? y : 0) + go(0, i + 1);
    ll j = (prev == 0 ? x : 0) + go(1, i + 1);
    ll ret = 0;
    if (s[i] == 'C') return dp[prev][i] = c;
    else if (s[i] == 'J') return dp[prev][i] = j;
    else return dp[prev][i] = min(c, j);
}

int main() {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> x >> y >> s;
        memset(dp, 0, sizeof dp);
        memset(found, 0, sizeof found);
        cout << "Case #" << tt << ": " << go(2, 0) << '\n';
    }
}