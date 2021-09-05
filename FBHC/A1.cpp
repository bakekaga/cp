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
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".txt").c_str(), "w", stdout);
    }
}

int main() {
    setIO("A1");
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        string str; cin >> str;
        long v = 0, c = 0, cur = 0, out = LONG_MAX;
        for (int i = 0; i < 26; i++) {
            char ch = 'A' + i;
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                for (int j = 0; j < sz(str); j++) { 
                    if (str[j] != ch) {
                        if (str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
                            cur+= 2;
                        }
                        else cur++;
                    }
                }
            }
            else {
                for (int j = 0; j < sz(str); j++) { 
                    if (str[j] != ch) {
                        if (str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
                            cur++;
                        }
                        else cur+= 2;
                    }
                }
            }
            out = min(out, cur);
            cur = 0;
        }
        cout << "Case #" << tt << ": " << out << '\n';
    }
    return 0;
}