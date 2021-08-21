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

pair<ll,ll> intervals[MAXN];

int main() {
    fileIO("socdist");
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals, intervals + m);
    
    // binary search
    ll lo = 0, hi = intervals[m - 1].second - intervals[0].first + 1;
    while (lo < hi) {
        // greedy algorithm
        ll mid = lo + (hi - lo + 1) / 2;
        int count = 1, intervalCount = 0;
        ll current = intervals[0].first;
        while ((current + mid) < intervals[m - 1].second) {
            while (current + mid > intervals[intervalCount].second) {
                intervalCount++;
            }
            current = max(intervals[intervalCount].first, current + mid);
            count++;
            if (count == n) break;
        }
        if (count >= n) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
    return 0;
}