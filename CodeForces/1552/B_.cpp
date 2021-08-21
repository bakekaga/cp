// Handle: bakekaga
// Problem Name: 1552B Running for Gold
// URL: https://codeforces.com/contest/1552/problem/B

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

struct Athlete {
    int id, r[5];
};

bool cmp(const Athlete &a, const Athlete &b) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (a.r[i] < b.r[i]) cnt++;
    }
    return cnt >= 3;
}

void solve() {
    int n; cin >> n;
    vector<Athlete> v(n);

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[i].r[j];
        }
        v[i].id = i;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i < n; i++) {
        if (!cmp(v[0], v[i])) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << v[0].id + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
