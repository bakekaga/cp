// Handle: bakekaga
// Problem Name: 1560B Who's Opposite?
// URL: https://codeforces.com/contest/1560/problem/B

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
    int a, b, c; cin >> a >> b >> c;
    int tot = 2 * abs(b - a);
    if (a > tot || b > tot || c > tot) cout << -1 << '\n';
    else cout << ((c + tot / 2) % tot ? (c + tot / 2) % tot : tot) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}