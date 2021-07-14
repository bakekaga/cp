// Intuitively the first step is to sort and then coordinate compress the
// points since only their relative positions matter. Suppose that we label
// the points as P1,P2, ..., Pn, ordered by ascending y coordinates. Then 
// if we consider the minimum rectangle containing some subset of points,
// clearly the bottom and top sides must be exactly on top of two points Pa
// and Pb, respectively, such that a < b; there cannot be more than 1 point
// on each side because the ys are distinct. Then all points Pi that could
// be in this rectangle must have Pa.y < Pi.y < Pb.y; however, considering
// the x coordinates, it becomes clear that some number of points satisfying
// the y condition must be inside the rectangle (namely, those with Pa.x <
// Pi.x < Pb.x), but there can also be points satisfying the y condition
// that do not have to be inside the rectangle. In particular, these are the
// points satisfying either 0 <= Pi.x < min(Pa.x, Pb.x) or max(Pa.x, Pb.x)
// < Pi.x <= n-1. Furthermore,the former must be on the left boundary of the
// rectangle, and the latter must be on the right boundary of the rectangle.
// Thus, for every pair of points Pa and Pb, it suffices to multiply the
// number of points satisfying the former condition by the number of points
// satisfying the latter condition, which can be done in O(1) with 2D prefix
// sums, so the total algorithm runs in O(n^2) with O(n^2) precomputation.

#include <bits/stdc++.h>
#define MAXN 2505
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

pair<ll,ll> cows[MAXN];
ll psums[MAXN][MAXN];

// comparator for sorting by y coordinates
bool cmp (pair<ll,ll> cow1, pair<ll,ll> cow2) {
    return cow1.second < cow2.second;
}

// O(1) rectangle sum
ll rsum(ll x1, ll y1, ll x2, ll y2) {
    return psums[x1+1][y1+1] - psums[x1+1][y2] - psums[x2][y1+1] + psums[x2][y2];
}

int main() {
    setIO();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    // sorting + coordinate compression
    sort(cows, cows + n, cmp);
    for (int i = 0; i < n; i++) cows[i].second = i+1;
    sort(cows, cows + n);
    for (int i = 0; i < n; i++) cows[i].first = i+1;
    
    // prefix sum precomputation
    for (int i = 0; i < n; i++) psums[cows[i].first][cows[i].second]++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            psums[i+1][j+1] += psums[i+1][j] + psums[i][j+1] - psums[i][j];
        }
    }
    
    ll ret = 0;
    // running the algorithm; remember that the array is sorted by ascending x coordinate
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ret += rsum(j, n-1, i, max(cows[i].second, cows[j].second)-1)
                * rsum(j, min(cows[i].second, cows[j].second)-1, i, 0);
        }
    }

    // don't forget empty subset
    cout << ret + 1 << '\n';
}