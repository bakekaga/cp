// Prefix sums problem, but an alternate sorting + iterating
// approach is possible. The prefix sums idea is to just store
// the broken signals as 1s and working signals as 0s and then
// iterate for the minimal k-subarray sum, which can be computed
// in O(n) time in total with prefix sum preprocessing.

#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int sigs[MAXN];
int presum[MAXN];

int main() {
    setIO("maxcross");
    int x, n, k, b, ret = INT_MAX;
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++) {
        cin >> x; sigs[x - 1]++;
    }
    
    for (int i = 0; i < n; i++) {
        presum[i + 1] = presum[i] + sigs[i];
    }

    for (int i = 0; i <= n - k; i++) {
        ret = min(ret, presum[i+k] - presum[i]);
    }
    cout << ret << '\n';
    return 0;
}
