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

struct mi {
    int v; explicit operator int() const { return v; }
    mi(ll _v) : v(_v%MOD) { v += (v<0)*MOD; }
    mi() : mi(0) {}
};
mi operator+(mi a, mi b) { return mi(a.v+b.v); }
mi operator-(mi a, mi b) { return mi(a.v-b.v); }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
 
struct Fence {
    int x, y, id;
    mi sum1, sum2;
};

Fence fences [MAXN];
vector<pair<int,int>> xsum[20001];
vector<pair<int,int>> ysum[20001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setIO("triangles");

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> fences[i].x >> fences[i].y;
        xsum[fences[i].x+10000].pb(mp(fences[i].y,i));
        ysum[fences[i].y+10000].pb(mp(fences[i].x,i));
    }

    for (int i = 0; i <= 20000; i++) {
        if (sz(xsum[i]) > 0) {
            mi cur = 0;
            sort(xsum[i].begin(), xsum[i].end());
            for (int j = 1; j < sz(xsum[i]); j++) {
                cur = cur + xsum[i][j].first - xsum[i][0].first;
            }
            fences[xsum[i][0].second].sum1 = cur;
            for (int j = 1; j < sz(xsum[i]); j++) {
                cur = cur + (2*j - sz(xsum[i])) * (xsum[i][j].first - xsum[i][j-1].first);
                fences[xsum[i][j].second].sum1 = cur;
            }
        }
    }

    for (int i = 0; i <= 20000; i++) {
        if (sz(ysum[i]) > 0) {
            mi cur = 0;
            sort(ysum[i].begin(), ysum[i].end());
            for (int j = 1; j < sz(ysum[i]); j++) {
                cur = cur + ysum[i][j].first - ysum[i][0].first;
            }
            fences[ysum[i][0].second].sum2 = cur;
            for (int j = 1; j < sz(ysum[i]); j++) {
                cur = cur + (2*j - sz(ysum[i])) * (ysum[i][j].first - ysum[i][j-1].first);
                fences[ysum[i][j].second].sum2 = cur;
            }
        }
    }

    mi ret = 0;
    for (int i = 0; i < n; i++) ret = ret + fences[i].sum1 * fences[i].sum2;

    cout << ret.v << '\n';
    return 0;
}