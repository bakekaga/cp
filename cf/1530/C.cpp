// Handle: bakekaga
// Problem Name: 1530C Pursuit
// URL: https://codeforces.com/contest/1530/problem/C

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

vector<ll> a, b;

bool ok(int x, ll ret, ll reti) {
    int n = sz(a);
    ret += x * 100;
    for (int i = n / 4; i < (n + x) / 4; i++) {
        ret-= a[i];
    }
    int fin = max(0, (n + x) / 4 - x); // ends at n / 4 - (x - x / 4) == n / 4 - (x - ((n + x) / 4 - n / 4))
    for (int i = n / 4 - 1; i >= fin; i--) {
        reti+= b[i];
    }
    return ret >= reti;
}

void solve() {
    a.clear(); b.clear();
    ll ret = 0, reti = 0;
    int in, n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        a.pb(in);
    }
    for (int i = 0; i < n; i++) {
        cin >> in;
        b.pb(in);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = n / 4; i < n; i++) {
        ret+= a[i];
        reti+= b[i];
    }

    ll out = -1;
    for (ll bb = n; bb >= 1; bb /= 2) {
        while (!ok(out + bb, ret, reti)) out+= bb;
    }

    cout << out + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
