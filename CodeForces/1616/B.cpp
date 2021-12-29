#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void solve() {
    int n, cnt = 1; string s;
    cin >> n >> s;
    char c = s[0]; bool first = true;
    for (int i = 1; i < n; i++) {
        if (s[i] < c && first) {
            cnt++;
            c = s[i];
            first = false;
        }
        else if (s[i] <= c && !first) {
            cnt++;
            c = s[i];
        }
        else {
            break;
        }
    }
    cout << s.substr(0, cnt);
    reverse(s.begin(), s.begin() + cnt);
    cout << s.substr(0, cnt) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}