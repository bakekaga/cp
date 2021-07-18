// Handle: bakekaga
// Problem Name: 1530A Putting Plates
// URL: https://codeforces.com/contest/1530/problem/B

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

int h, w;

void check(int i, int j, vector<vector<int>> &plates) {
    if (i && j && plates[i - 1][j - 1]) {
        cout << 0;
        return;
    }
    if (i && plates[i - 1][j]) {
        cout << 0;
        return;
    }
    if (j && plates[i][j - 1]) {
        cout << 0;
        return;
    }
    if (i && j < w - 1 && plates[i - 1][j + 1]) {
        cout << 0;
        return;
    }
    if (j && i < h - 1 && plates[i + 1][j - 1]) {
        cout << 0;
        return;
    }
    if (i < h - 1 && j < w - 1 && plates[i + 1][j + 1]) {
        cout << 0;
        return;
    }
    if (i < h - 1 && plates[i + 1][j]) {
        cout << 0;
        return;
    }
    if (j < w - 1 && plates[i][j + 1]) {
        cout << 0;
        return;
    }
    plates[i][j] = 1;
    cout << 1;
}

void solve() {
    cin >> h >> w;
    vector<vector<int>> plates(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        if (!i || i == h - 1) {
            for (int j = 0; j < w; j++) {
                check(i, j, plates);
            }
        }
        else {
            check(i, 0, plates);
            for (int j = 1; j < w - 1; j++) cout << 0;
            check(i, w - 1, plates);
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
