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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int mn = INF;
    if (arr[n - 1] - arr[1] == n - 2 && arr[1] - arr[0] > 2) mn = 2;
    else if (arr[n - 2] - arr[0] == n - 2 && arr[n - 1] - arr[n - 2] > 2) mn = 2;
    else {
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && arr[j] - arr[i] < n) j++;
            mn = min(mn, n - j + i);
        }
    }
    cout << mn << '\n';

    int mx = 0;
    for (int i = 1; i < n; i++) {
        mx+= arr[i] - arr[i - 1] - 1;
    }
    cout << max(mx - arr[1] + arr[0] + 1, mx - arr[n - 1] + arr[n - 2] + 1) << '\n';
    return 0;
}