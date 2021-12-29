#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void solve() {
    int n, cnt = 1; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());
    int cur = a[0]; bool first = false;
    if (cur == 0) first = true;
    for (int i = 1; i < n; i++) {
        if (a[i] == cur && first) continue;
        if (a[i] == cur) {
            cnt++;
            first = true;
        }
        else {
            cnt++;
            cur = a[i];
            first = false;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}