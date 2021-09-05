#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

ll a[MAXN];

bool ok(double x, int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+= floor(a[i] / x);
    }
    return sum >= k;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    double lo = 0, hi = 1e8;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (ok(mid, n, k)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    cout << setprecision(20) << lo << '\n';
    return 0;
}