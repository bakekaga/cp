#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    string c = s;
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != c[i]) cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
