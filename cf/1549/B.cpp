// Handle: bakekaga
// Problem Name: 1549B Gregor and the Pawn Game
// URL: https://codeforces.com/contest/1549/problem/B

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void solve() {
    int n, out = 0; cin >> n;
    string b1, b2; cin >> b1 >> b2;
    vector<int> captured(n);

    for (int i = 0; i < n; i++) {
        if (b2[i] == '1') {
            if (i && b1[i - 1] == '1' && !captured[i - 1]) {
                captured[i - 1]++; out++;
            } 
            else if (b1[i] == '0' && !captured[i]) {
                captured[i]++; out++;
            }
            else if (i < n - 1 && b1[i + 1] == '1' && !captured[i + 1]) {
                captured[i + 1]++; out++;
            }
        }
    }
    cout << out << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
