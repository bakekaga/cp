#include <bits/stdc++.h>
#define MAXN 50005
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

struct Cow {
    ll x, y;
    int id;
};

bool cmp(const Cow &a, const Cow &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

ll ret;

Cow cows[MAXN];

void solve(int n) {
    sort(cows, cows+n, cmp);
    vector<ll> premin(n+1);
    vector<ll> premax(n+1);
    vector<ll> sufmin(n+1);
    vector<ll> sufmax(n+1);

    premin[0] = INT_MAX;
    premax[0] = 0;
    sufmin[n] = INT_MAX;
    sufmax[n] = 0;

    for (int i = 0; i < n; i++) {
        premin[i + 1] = min(premin[i], cows[i].y);
        premax[i + 1] = max(premax[i], cows[i].y);
        sufmin[n - i - 1] = min(sufmin[n - i], cows[n - i - 1].y);
        sufmax[n - i - 1] = max(sufmax[n - i], cows[n - i - 1].y);
    }

    ll totalarea = (cows[n - 1].x - cows[0].x) * (premax[n] - premin[n]);

    for (int i = 1; i < n; i++) {
        ll area1 = (premax[i] - premin[i]) * (cows[i - 1].x - cows[0].x);
        ll area2 = (sufmax[i] - sufmin[i]) * (cows[n - 1].x - cows[i].x);
        ret = max(ret, totalarea - area1 - area2);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setIO("split");

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].id = i;
    }
    solve(n);

    for (int i = 0; i < n; i++) {
        int temp = cows[i].x;
        cows[i].x = cows[i].y;
        cows[i].y = temp;
    }
    solve(n);
    cout << ret << '\n';
    return 0;
}
