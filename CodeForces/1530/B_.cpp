#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void check(int i, int j, vector<vector<int>> &plates) {
    if (plates[i - 1][j - 1] ||
    plates[i - 1][j] ||
    plates[i][j - 1] ||
    plates[i - 1][j + 1] ||
    plates[i + 1][j - 1] ||
    plates[i + 1][j + 1] ||
    plates[i + 1][j] ||
    plates[i][j + 1]) cout << 0;
    else {
        cout << 1;
        plates[i][j] = 1;
    }
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> plates(h + 2, vector<int>(w + 2));
    for (int i = 1; i <= h; i++) {
        if (i == 1 || i == h) {
            for (int j = 1; j <= w; j++) {
                check(i, j, plates);
            }
        }
        else {
            check(i, 1, plates);
            for (int j = 2; j <= w - 1; j++) cout << 0;
            check(i, w, plates);
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
