#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

bool ok(ll mid, ll n, ll x, ll y) {
    return (mid - x) / y + mid / x >= n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x, y; cin >> n >> x >> y;
    if (x > y) swap(x, y);
    ll lo = 1, hi = n * x;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (!ok(mid, n, x, y)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo << '\n';
    return 0;
}