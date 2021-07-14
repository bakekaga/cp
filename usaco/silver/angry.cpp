// Greedy/binary search problem. The difficult part is figuring out how to check if
// a given radius works, which can be done with a greedy algorithm where we always
// launch the cow such that it will clip the leftmost haybale at the leftmost edge
// of its blast radius and then launch the next cow to cover the leftmost haybale that
// was not covered by the previous one. Then we just binary search for the best radius.

#include <iostream>
#include <algorithm>
#include <array>

#define MAXN 50000

using namespace std;
typedef long long ll;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

ll haybales[MAXN];
int n, k;

bool ok(ll r) {
    int count = 1;
    ll current = haybales[0];
    while ((current + 2 * r) < haybales[n - 1]) {
        auto i = lower_bound(haybales, haybales + n, current + 2 * r + 1);
        current = haybales[i - haybales];
        count++;
    }
    return count <= k;
}

int main() {
    fileIO("angry");
    // ios::sync_with_stdio;
    // cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> haybales[i];
    }

    sort(haybales, haybales + n);
    
    int x = -1;

    for (ll r = (haybales[n-1] - haybales[0]) / (2 * k); r >= 1; r /= 2) {
        while(!ok(x + r)) x+= r;
    }

    cout << x + 1 << '\n';
    return 0;
}