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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<string, int> dynamics;
    dynamics["ppp"] = 0;
    dynamics["pp"] = 1;
    dynamics["p"] = 2;
    dynamics["mp"] = 3;
    dynamics["mf"] = 4;
    dynamics["f"] = 5;
    dynamics["ff"] = 6;
    dynamics["fff"] = 7;

    vector<array<int, 2>> dynOrder(m + 1);
    for (int i = 0; i < m; i++) {
        int curStart;
        string curDynString;
        cin >> curStart >> curDynString;
        dynOrder[i] = {curStart - 1, dynamics[curDynString]};
    }
    dynOrder[m] = {n, 10};

    vector<vector<int>> classes(8);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < dynOrder[i + 1][0]) {
            classes[dynOrder[i][1]].push_back(a[j]);
            j++;
        }
    }

    for (vector<int> &v : classes) {
        sort(v.begin(), v.end());
    }

    ll cnt = 0;
    for (int i = 0; i < sz(classes); i++) {
        for (int curNote : classes[i]) {
            for (int j = i + 1; j < sz(classes); j++) {
                if (classes[j].empty()) continue;
                cnt += upper_bound(classes[j].begin(), classes[j].end(), curNote) - classes[j].begin();
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}