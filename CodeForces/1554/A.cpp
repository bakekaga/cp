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
    ll last, n, cur, out = 0; cin >> n >> last;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        out = max(out, last * cur);
        last = cur;
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
