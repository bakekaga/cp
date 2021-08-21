#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long

using namespace std;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    b %= (m - 1);
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res*= a;
            res%= m;
        }
        a*= a;
        a%= m;
        b>>= 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    cout << binpow(2, n, MOD);
    return 0;
}