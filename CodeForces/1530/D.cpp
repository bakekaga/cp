// Handle: bakekaga
// Problem: 1530D Secret Santa
// URL: https://codeforces.com/contest/1530/problem/D

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

string out;

bool check(vector<int> &a, vector<int> b, vector<int> &count) {
    out = "";
    for (int i = 1; i < sz(a); i++) {
        if (count[a[i]] == i) {
            out+= to_string(a[i]) + " ";
        }
        else {
            if (b[sz(b) - 1] == i && sz(b) == 1) {
                return true;
            }
            else if (b[sz(b) - 1] == i) {
                swap(b[sz(b) - 2], b[sz(b) - 1]);
            }
            out+= to_string(b[sz(b) - 1]) + " ";
            b.pop_back();
        }
    }
    return false;
}

void solve() {
    int n, amt = 0; cin >> n;
    vector<int> a(n + 1, 0), b;
    vector<int> count(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        count[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (!count[i]) b.pb(i);
        else amt++;
    }
    
    if (check(a, b, count)) {
        reverse(b.begin(), b.end());
        if (check(a, b, count)) {
            out = "";
            // there always exists another employee with the same wish
            // as the one who is stuck wishing for themselves
            for (int i = 1; i <= n; i++) {
                if (i != b[0] && a[b[0]] == a[i]) {
                    count[b[0]] = i;
                    swap(b[0], a[i]);
                    break;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (count[a[i]] == i) {
                    out+= to_string(a[i]) + " ";
                }
                else {
                    out+= to_string(b[0]) + " ";
                }
            }
        }
    }
    cout << amt << '\n' << out << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
