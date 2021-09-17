#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 1) cout << "a\n";
    else {
        for (int i = 0; i < n/2; i++) cout << "a";
        if (n & 1) cout << "bc";
        else cout << "b";
        for (int i = 0; i < n/2 - 1; i++) cout << "a";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
