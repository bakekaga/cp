#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
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

struct Fence {
    // sum1 is the sum of the heights of all the triangles
    // that use this fence as an anchor point, sum2 is the
    // sum of the bases of all the triangles that use this
    // fence as an anchor point; recall that the anchor point
    // of a right triangle is the vertex where the right
    // angle is.
    int x, y;
    ll sum1, sum2;
};

// fences are our fences, xsum represents all of the possible
// x coordinates of our fences, ysum represents all of the
// possible y coordinates of our fences
Fence fences[MAXN];
vector<pair<int,int>> xsum[20001];
vector<pair<int,int>> ysum[20001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setIO("triangles");

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> fences[i].x >> fences[i].y;
        // we add 100000 to make all of our coordinates positive
        // so that we won't have negative indices
        xsum[fences[i].x + 10000].pb(mp(fences[i].y, i));
        ysum[fences[i].y + 10000].pb(mp(fences[i].x, i));
    }

    for (int i = 0; i <= 20000; i++) {
        if (sz(xsum[i]) > 0) {
            // cur is the value of the current s_i
            ll cur = 0;
            // first we sort all of the y coordinates of each set
            // of points with the same x coordinate
            sort(xsum[i].begin(), xsum[i].end());
            // then we compute the value s_1 of this set:
            // the sum of the heights of all the triangles that
            // have anchor point at (i, xsum[i][0].first)
            for (int j = 1; j < sz(xsum[i]); j++) {
                cur+= xsum[i][j].first - xsum[i][0].first;
            }
            fences[xsum[i][0].second].sum1 = cur;
            // then we compute the rest of the s_i for this set
            for (int j = 1; j < sz(xsum[i]); j++) {
                cur+= (2 * j - sz(xsum[i])) * (xsum[i][j].first - xsum[i][j - 1].first);
                fences[xsum[i][j].second].sum1 = cur;
            }
        }
    }

    // we do the sums of bases in exactly the same way
    for (int i = 0; i <= 20000; i++) {
        if (sz(ysum[i]) > 0) {
            ll cur = 0;
            sort(ysum[i].begin(), ysum[i].end());
            for (int j = 1; j < sz(ysum[i]); j++) {
                cur+= ysum[i][j].first - ysum[i][0].first;
            }
            fences[ysum[i][0].second].sum2 = cur;
            for (int j = 1; j < sz(ysum[i]); j++) {
                cur+= (2 * j - sz(ysum[i])) * (ysum[i][j].first - ysum[i][j - 1].first);
                fences[ysum[i][j].second].sum2 = cur;
            }
        }
    }

    // finally we compute the total area
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ret+= fences[i].sum1 * fences[i].sum2 % MOD;
        ret%= MOD;
    }
    cout << ret << '\n';
    return 0;
}
