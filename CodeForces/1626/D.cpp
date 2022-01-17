#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-6;

int mid(int x) {
    if (x == 0) return 1;
    return ((__builtin_popcount(x) == 1) ? x : (1<<(32 - __builtin_clz(x)))) - x;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    vector<pair<int, int>> front, back;
    for (int i = 1; i <= n; i<<= 1) {
        int ind = lower_bound(arr.begin(), arr.end(), arr[i - 1]) - arr.begin();
        if (i == n || arr[i - 1] != arr[i]) {
            front.pb(mp(i, 0));
        }
        else {
            front.pb(mp(i, i - ind));
        }
    }
    for (int i = 1; i <= n; i<<= 1) {
        int ind = upper_bound(arr.begin(), arr.end(), arr[n - i]) - arr.begin();
        if (i == n || (arr[n - i] != arr[n - i - 1])) {
            back.pb(mp(i, 0));
        }
        else {
            back.pb(mp(i, i - (n - ind)));
        }
    }

    int ans = n + 1;
    for (auto x : front) {
        for (auto y : back) {
            if (x.first - x.second - 1 >= n - y.first + y.second) continue;
            ans = min(ans, x.second + y.second + mid(n - x.first - y.first + x.second + y.second));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}