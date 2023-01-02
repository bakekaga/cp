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
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (k--) {
        int x; cin >> x;
        int lo = -1, hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] < x) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        cout << (a[lo + 1] == x ? "YES" : "NO") << '\n';
    }
    return 0;
}