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
    int n, sum = 0; cin >> n;
    string s[2]; cin >> s[0] >> s[1];
    bool one = false, zero = false;
    for (int i = 0; i < n; i++) {
        int x = s[0][i] + s[1][i] - '0' - '0';
        if (x == 0) {
            if (one) {
                sum+= 2;
                one = false;
            }
            else {
                zero = true;
                sum++;
            }
        }
        else if (x == 1) {
            one = false;
            zero = false;
            sum+= 2;
        }
        else if (x == 2) {
            if (zero) {
                sum++;
                zero = false;
            }
            else {
                one = true;
            }
        }
    }
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}