#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
bool intersect(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) swap(a, b);
    return a.second > b.first && a.second < b.second;
}
 
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(k);
    vector<int> used(2 * n), unused;
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > v[i].second) swap(v[i].first, v[i].second);
        v[i].first--; v[i].second--;
        used[v[i].first] = used[v[i].second] = true;
    }
 
    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) unused.pb(i);
    }
 
    for (int i = 0; i < n - k; i++) {
        v.pb(mp(unused[i], unused[i + n - k]));
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans+= intersect(v[i], v[j]);
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
