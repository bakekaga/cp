#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
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
    setIO("A1");
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, out = 0; string str;
        cin >> n >> str;
        char cur = 'A';
        for (int i = 0; i < n; i++) {
            if (str[i] != 'F') {
                if (cur == 'A') cur = str[i];
                else if (str[i] != cur) {
                    cur = str[i];
                    out++;
                }
            }
        }
        cout << "Case #" << tt << ": " << out << '\n';
    }
}