#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000000000000
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

ll floordiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), presums(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        presums[i + 1] = presums[i] + a[i];
    }
    ll ret = 1e18;
    for (int i = 0; i < n; i++) {
        ll x = a[0] - floordiv(k - presums[n - i] + a[0], i + 1LL);
        ret = min(ret, max(x, 0LL) + i);
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}