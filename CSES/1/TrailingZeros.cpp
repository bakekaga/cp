#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll ret = 0, a = 5;
    while (n / a > 0) {
        ret+= n / a;
        a*= 5;
    }
    cout << ret << '\n';
    return 0;
}