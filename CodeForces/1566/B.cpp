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
    string s; cin >> s; 
    char cur = s[0]; int sum = 0; s.pb('2');
    for (int i = 0; i < sz(s); i++) {
        if (s[i] != cur) {
            sum+= cur == '0' ? 1 : 0;
            cur = s[i];
        }
    }
    cout << min(2, sum) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}