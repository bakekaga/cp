#include <bits/stdc++.h>

#define MOD 10000007
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cout << (i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2)) << '\n';
    }
    return 0;
}