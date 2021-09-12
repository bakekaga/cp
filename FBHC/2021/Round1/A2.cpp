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
        freopen((prob + ".txt").c_str(), "r", stdin);
        freopen((prob + "out.txt").c_str(), "w", stdout);
    }
}

int main() {
    setIO("A2");
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n; ll out = 0; string str;
        cin >> n >> str;
        pair<char, int> cur = mp('A', -1);
        vector<pair<int, int>> changes;
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (str[i] != 'F') {
                if (f) {
                    cur = mp(str[i], i);
                    f = false;
                }
                else if (str[i] == cur.first) {
                    cur.second = i;
                }
                else {
                    changes.pb(mp(cur.second, i));
                    cur = mp(str[i], i);
                }
            }
        }
        for (int i = 0; i < sz(changes); i++) {
            out+= 1LL * (changes[i].first + 1) * (n - changes[i].second) % MOD;
            out%= MOD;
        }
        cout << "Case #" << tt << ": " << out << '\n';
    }
}