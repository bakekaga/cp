#include <bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int coins[MAXN];
ll dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 1; i <= x; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0) continue;
            dp[i] = min(dp[i], 1LL + dp[i - coins[j]]);
        }
    }
    cout << (dp[x] != INT_MAX ? dp[x] : -1) << '\n';
    return 0;
}