#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    ll x; cin >> x;
    string s = to_string(x);
    while (x != 1) {
        if (x % 2 == 0) x/= 2;
        else x = 3 * x + 1;
        s+= " " + to_string(x);
    }
    cout << s << '\n';
    return 0;
}
