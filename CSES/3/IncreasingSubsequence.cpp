#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        dp[i + 1] = INT_MAX;
        int lo = -1, hi = i + 1;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;
            if (dp[mid] < x) lo = mid;
            else hi = mid;
        }
        dp[hi] = min(dp[hi], x);
    }

    for (int i = n; i >= 1; i--) {
        if (dp[i] != INT_MAX) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}