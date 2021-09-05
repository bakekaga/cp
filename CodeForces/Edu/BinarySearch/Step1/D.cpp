#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> k;
    while (k--) {
        int l, r; cin >> l >> r;
        // cout << upper_bound(a, a + n, r) - lower_bound(a, a + n, l) << '\n';
        int llo = -1, lhi = n;
        while (llo + 1 < lhi) {
            int mid = (llo + lhi) / 2;
            if (a[mid] < l) {
                llo = mid;
            }
            else {
                lhi = mid;
            }
        }
        int rlo = -1, rhi = n;
        while (rlo + 1 < rhi) {
            int mid = (rlo + rhi) / 2;
            if (a[mid] <= r) {
                rlo = mid;
            }
            else {
                rhi = mid;
            }
        }
        cout << rhi - llo - 1 << '\n';
    }
    return 0;
}