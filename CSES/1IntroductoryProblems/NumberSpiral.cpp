#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll calculate(ll x, ll y) {
    if (x > y) {
        if (x % 2 == 0) return (x - 1) * (x - 1) + y;
        else return x * x - y + 1;
    }
    if (x < y) {
        if (y % 2 == 0) return y * y - x + 1;
        else return (y - 1) * (y - 1) + x;
    }
    return x * x - x + 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> y >> x;
        cout << calculate(x, y) << '\n';
    }
}