#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll a, b;
    while (n--) {
        cin >> a >> b;
        if (a <= 2 * b && b <= 2 * a && (a + b) % 3 == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}