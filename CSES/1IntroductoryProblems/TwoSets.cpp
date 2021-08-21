#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    if (n % 4 == 0 || n % 4 == 3) {
        cout << "YES\n";
        
        ll half = n * (n + 1) / 4;
        int i = n, skip = 0;
        string str = "";
        while (half - i > 0) {
            str+= to_string(i) + " ";
            half-= i;
            i--;
        }

        if (half == 0) cout << n - i << "\n" + str + "\n" << i << '\n';
        else cout << n - i + 1 << "\n" + str + to_string(half) + "\n" << i - 1 << '\n';

        while (i > 0) {
            if (i != half) cout << i << " ";
            i--;
        }
    }
    else cout << "NO\n";

    return 0;
}
