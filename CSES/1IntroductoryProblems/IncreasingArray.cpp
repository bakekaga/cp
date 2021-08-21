#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; ll best = 0LL; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i > 0 && v[i - 1] > v[i]) {
            best+= (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    cout << best << '\n';
    return 0;
}