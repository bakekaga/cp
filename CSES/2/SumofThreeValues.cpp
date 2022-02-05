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
    ll x; cin >> x;
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1, k = n - 1; j < k;) {
            if (v[i].first + v[j].first + v[k].first == x) {
                cout << v[i].second << ' ' << v[j].second << ' ' << v[k].second << '\n';
                return 0;
            }
            else if (v[i].first + v[j].first + v[k].first < x) j++;
            else k--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}