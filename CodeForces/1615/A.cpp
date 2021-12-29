#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void solve() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll in; cin >> in;
        sum+= in;
    }
    if (sum % n == 0) cout << 0 << '\n';
    else cout << 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}