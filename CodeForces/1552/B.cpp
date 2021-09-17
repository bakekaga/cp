#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(5));

    int ret = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
            if (v[ret][j] > v[i][j]) cnt++;
        }
        if (cnt >= 3) ret = i;
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (v[ret][j] > v[i][j]) cnt++;
        }
        if (cnt >= 3) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ret + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
