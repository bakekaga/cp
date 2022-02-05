#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int) (x).size()

using namespace std;

int alphabet[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string str, c = "", out = ""; cin >> str;
    for (int i = 0; i < sz(str); i++) {
        alphabet[str[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 != 0) {
            if (c == "") c = char('A' + i);
            else {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
        for (int j = 0; j < alphabet[i] / 2; j++) {
            out+= char('A' + i);
        }
    }
    cout << out << c;
    for (int i = sz(out) - 1; i >= 0; i--) cout << out[i];
}