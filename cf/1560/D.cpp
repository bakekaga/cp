// Handle: bakekaga
// Problem: 1560D Make a Power of Two
// URL: https://codeforces.com/contest/1560/problem/D

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void solve() {
    int n; cin >> n;
    string str = to_string(n);
    int ans = sz(str) + 1;
    for (int i = 0; i <= 60; i++) {
        string cur = to_string(1LL << i);
        int j = 0, k = 0;
        while (j < sz(str)) {
            if (k < sz(cur) && str[j] == cur[k]) k++;
            j++;
        }
        ans = min(ans, sz(str) - k + sz(cur) - k);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}