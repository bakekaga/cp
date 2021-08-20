// Handle: bakekaga
// Problem Name: 1560A Dislike of Threes
// URL: https://codeforces.com/contest/1560/problem/A

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void solve() {
    int k, cur = 0; cin >> k;
    for (int i = 0; i < k; i++) {
        while (cur % 3 == 0 || cur % 10 == 3) cur++;
        cur++;
    }
    cout << cur - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}