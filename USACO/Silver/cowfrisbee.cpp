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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<pair<int, int>> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first < a[i]) {
            ans+= abs(s.top().second - i) + 1;
            s.pop();
        }
        s.push({a[i], i});
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first < a[i]) {
            ans+= abs(s.top().second - i) + 1;
            s.pop();
        }
        s.push({a[i], i});
    }
    while (!s.empty()) {
        s.pop();
    }
    cout << ans << '\n';
    return 0;
}