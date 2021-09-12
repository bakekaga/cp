#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int x, y, out = 0; string str;
        cin >> x >> y >> str;
        char cur = str[0];
        for (int i = 1; i < sz(str); i++) {
            if (cur == '?') {
                if (str[i] == 'C') cur = str[i];
                else if (str[i] == 'J') cur = str[i];
            }
            else if (cur == 'C' && str[i] == 'J') {
                cur = str[i];
                out+= x;
            }
            else if (cur == 'J' && str[i] == 'C') {
                cur = str[i];
                out+= y;
            }
        }
        cout << "Case #" << tt << ": " << out << '\n';
    }
}