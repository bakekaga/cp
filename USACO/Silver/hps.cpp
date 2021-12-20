// Prefix sums problem. There are 9(n + 1) combinations, so with
// O(1) prefix sums we can compute them all in O(n) time.

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int presum[MAXN][3];

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
    int n, out = 0; cin >> n; string str = "";
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "H") {
            presum[i + 1][0] = presum[i][0];
            presum[i + 1][1] = presum[i][1] + 1;
            presum[i + 1][2] = presum[i][2];
        }
        else if (str == "P") {
            presum[i + 1][0] = presum[i][0];
            presum[i + 1][1] = presum[i][1];
            presum[i + 1][2] = presum[i][2] + 1;
        }
        else if (str == "S") {
            presum[i + 1][0] = presum[i][0] + 1;
            presum[i + 1][1] = presum[i][1];
            presum[i + 1][2] = presum[i][2];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                out = max(out, presum[i][j] + presum[n][k] - presum[i][k]);
            }
        }
    }

    cout << out << '\n';
    return 0;
}