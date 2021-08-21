// Handle: bakekaga
// Problem Name: 1552C Maximize the Intersections
// URL: https://codeforces.com/contest/1552/problem/C

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace __gnu_pbds;

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
    sort(v.begin(), v.end());
    
    int ans = 0;
    ordered_set processed;
    for (int i = 0; i < n; i++) {
        int first = processed.order_of_key(v[i].first);
        int last = processed.order_of_key(v[i].second);
        ans+= last - first;
        processed.insert(v[i].second);
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
