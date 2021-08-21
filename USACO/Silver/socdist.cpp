#include <iostream>
#include <algorithm>
#include <array>

#define MAXN 100000

using namespace std;
typedef long long ll;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int n, m;
pair<ll,ll> intervals[MAXN];

// greedy algorithm
bool ok(ll d) {
    int count = 1, intervalCount = 0;
    ll current = intervals[0].first;
    while ((current + d) < intervals[m - 1].second) {
        while (current + d > intervals[intervalCount].second) {
            intervalCount++;
        }
        current = max(intervals[intervalCount].first, current + d);
        count++;
        if (count == n) return true;
    }
    return count >= n;
}

int main() {
    fileIO("socdist");

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals, intervals + m);
    // binary search
    ll x = 0;
    for (ll b = 1000000000LL; b >= 1; b/= 2) {
        while (ok(x + b)) x += b;
    }
    cout << x << '\n';
    return 0;
}