// Handle: bakekaga
// Problem Name: 1549C Web of Lies
// URL: https://codeforces.com/contest/1549/problem/C

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, q, x, y; cin >> n >> m;
    vector<ordered_set> nobles(n + 1);
    set<int> survivors;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        nobles[x].insert(y);
        nobles[y].insert(x);
    }

    for (int i = 1; i < n; i++) {
        if (nobles[i].order_of_key(i) == nobles[i].order_of_key(n + 1)) {
            survivors.insert(i);
        }
    }
    survivors.insert(n);

    cin >> q;
    while (q--) {
        int id; cin >> id;
        if (id == 1) {
            cin >> x >> y;
            nobles[x].insert(y);
            nobles[y].insert(x);
            if (x > y && survivors.count(y)) {
                survivors.erase(y);
            }
            else if (y > x && survivors.count(x)) {
                survivors.erase(x);
            }
        }
        else if (id == 2) {
            cin >> x >> y;
            nobles[x].erase(y);
            nobles[y].erase(x);
            if (x > y && nobles[y].order_of_key(y) == nobles[y].order_of_key(n + 1)) {
                survivors.insert(y);
            }
            else if (y > x && nobles[x].order_of_key(x) == nobles[x].order_of_key(n + 1)) {
                survivors.insert(x);
            }
        }
        else {
            cout << sz(survivors) << '\n';
        }
    }
    return 0;
}
