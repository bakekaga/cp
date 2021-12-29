#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int presums[19][MAXN];

void solve() {
    int l, r; cin >> l >> r;
    int ret = 0;
    for (int k = 0; k <= 18; k++) {
        ret = max(presums[k][r] - presums[k][l - 1], ret);
    }
    cout << r - l + 1 - ret << '\n';
}

int main() {
    for (int i = 1; i < MAXN; i++) {
        for (int k = 0; k <= 18; k++) {
            if (i & (1<<k)) presums[k][i] = presums[k][i - 1] + 1;
            else presums[k][i] = presums[k][i - 1];
        }
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}