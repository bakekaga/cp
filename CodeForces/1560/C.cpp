#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void solve() {
    int k; cin >> k;
    int sq = 1;
    while (sq * sq < k) sq++;

    int q = sq * sq, q_ = (sq - 1) * (sq - 1), x = 1;
    
    if (k - q_ == q - k) cout << sq << ' ' << sq << '\n';
    else if (k - q_ > q - k) {
        while (q > k) {
            q--;
            x++;
        }
        cout << sq << ' ' << x << '\n';
    }
    else {
        q_++;
        while (q_ < k) {
            q_++;
            x++;
        }
        cout << x << ' ' << sq << '\n';
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