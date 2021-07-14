#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

bool cmp (pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

pair<ll, ll> arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setIO("mountains");
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        arr[i] = mp(x - y,x + y);
    }
    sort(arr, arr + n, cmp);
    
    ll right = -1, ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second > right) {
            ans++;
            right = arr[i].second;
        }
    }

    cout << ans << '\n';
    return 0;
}