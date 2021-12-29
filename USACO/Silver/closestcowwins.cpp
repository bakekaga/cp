#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int k, m, n; cin >> k >> m >> n;
    vector<pair<ll, ll>> patches(k);
    vector<ll> intervals(m), vals;
    for (int i = 0; i < k; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> intervals[i];
    }
    sort(patches.begin(), patches.end());
    sort(intervals.begin(), intervals.end());

    // first value, all left of first interval
    vals.pb(0); int i = 0, j = 0;
    while (i < k) {
        if (patches[i].first > intervals[0]) break;
        vals[0]+= patches[i].second;
        i++;
    }

    // m - 1 intervals
    while (j < m - 1) {
        vals.pb(0);
        while (i < k && patches[i].first < (intervals[j + 1] + intervals[j]) / 2LL) {
            vals[sz(vals) - 1]+= patches[i].second;
            i++;
        }
        vals.pb(0);
        while (i < k && patches[i].first < intervals[j + 1]) {
            vals[sz(vals) - 1]+= patches[i].second;
            i++;
        }
        j++;
    }

    // last value, all right of last interval
    vals.pb(0);
    while (i < k) {
        vals[sz(vals) - 1]+= patches[i].second;
        i++;
    }

    sort(vals.begin(), vals.end(), greater<ll>());
    ll out = 0;
    for (int i = 0; i < n; i++) out+= vals[i];
    cout << out << '\n';
    return 0;
}