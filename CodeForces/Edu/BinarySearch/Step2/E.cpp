#include <bits/stdc++.h>
#define MAXN 10000000005
#define MOD 1000000007
#define INF 1000000000
#define EPS 0.000001
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

bool ok(double mid, double n) {
    return (mid * mid + sqrt(mid) - n) <= EPS;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double n; cin >> n;
    double lo = 0, hi = MAXN;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (ok(mid, n)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    cout << setprecision(20) << lo << '\n';
    return 0;
}