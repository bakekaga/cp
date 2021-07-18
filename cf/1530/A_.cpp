// Handle: bakekaga
// Problem Name: 1530A Binary Decimal
// URL: https://codeforces.com/contest/1530/problem/A

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
    int n; cin >> n;
    int ret = 0;
    while (n > 0) {
        ret = max(ret, n % 10);
        n/= 10;
    }
    cout << ret << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
