#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<int> amtAt(n), suffmax(n + 1);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && arr[j] - arr[i] <= k) {
            j++;
        }
        amtAt[i] = j - i;
    }
    for (int i = n - 1; i >= 0; i--) {
        suffmax[i] = max(amtAt[i], suffmax[i + 1]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, amtAt[i] + suffmax[amtAt[i] + i]);
    }
    cout << res << '\n';
    return 0;
}
