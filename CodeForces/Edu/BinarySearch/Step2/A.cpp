#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll w, h, n; cin >> w >> h >> n;
    ll lo = 0, hi = max(w, h) * n + 1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if ((double) (mid / h) < (double) n / (double) (mid / w)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    cout << lo + 1 << '\n';
    return 0;
}