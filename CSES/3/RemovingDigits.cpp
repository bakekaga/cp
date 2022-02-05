#include <bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int j = i;
        dp[i] = INT_MAX;
        while (j > 0) {
            if (j % 10) dp[i] = min(dp[i], dp[i - (j % 10)] + 1);
            j/= 10;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}