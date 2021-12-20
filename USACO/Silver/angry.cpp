// Greedy/binary search problem. The difficult part is figuring out how to check if
// a given radius works, which can be done with a greedy algorithm where we always
// launch the cow such that it will clip the leftmost haybale at the leftmost edge
// of its blast radius and then launch the next cow to cover the leftmost haybale that
// was not covered by the previous one. Then we just binary search for the best radius.

#include <bits/stdc++.h>
#define MAXN 50000
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

ll haybales[MAXN];
int n, k;

bool ok(ll r) {
    int count = 1;
    ll current = haybales[0];
    while ((current + 2 * r) < haybales[n - 1]) {
        current = haybales[lower_bound(haybales, haybales + n, current + 2 * r + 1) - haybales];
        count++;
    }
    return count <= k;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> haybales[i];
    }

    sort(haybales, haybales + n);
    int x = -1;
    for (ll b = (haybales[n - 1] - haybales[0]) / (2 * k); b >= 1; b/= 2) {
        while(!ok(x + b)) x+= b;
    }
    cout << x + 1 << '\n';
    return 0;
}