// Handle: bakekaga
// Problem: 1530E Minimax
// URL: https://codeforces.com/contest/1530/problem/E

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int alphabet[26];

void print(int i) {
    while(alphabet[i]--) cout << (char) (i + 'a');
}

void solve() {
    memset(alphabet, 0, sizeof alphabet);
    string str; cin >> str;
    pair<int, int> m = mp(MAXN, MAXN);
    int f = MAXN, s = MAXN, t = MAXN;
    for (int i = 0; i < str.size(); i++) {
        alphabet[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i]) {
            if (f == MAXN) f = i;
            else if (s == MAXN) s = i;
            else if (t == MAXN) t = i;
            if (m.first > alphabet[i]) {
                m.first = alphabet[i];
                m.second = i;
            }
        }
    }
    if (m.first == str.size()) {
        cout << str;
        alphabet[m.second] = 0;
    }
    // abbbbccc...
    else if (m.first == 1) {
        cout << (char) (m.second + 'a');
        alphabet[m.second] = 0;
        for (int i = f; i < 26; i++) {
            print(i);
        }
    }
    else {
        // aa...
        if (2 * (alphabet[f] - 1) <= str.size()) {
            cout << (char) (f + 'a') << (char) (f + 'a');
            alphabet[f]-= 2;
            for (int i = f + 1; i < 26; i++) {
                while (alphabet[i]--) {
                    cout << (char) (i + 'a');
                    if (alphabet[f]) {
                        cout << (char) (f + 'a');
                        alphabet[f]--;
                    }
                }
            }
        }
        // ab...
        else {
            cout << (char) (f + 'a') << (char) (s + 'a');
            alphabet[f]--;
            alphabet[s]--;
            // abbbbbaaaa
            if (t == MAXN) {
                print(s);
                print(f);
            }
            // abaaaacbbb...
            else {
                print(f);
                cout << (char) (t + 'a'); alphabet[t]--;
                for (int i = s; i < 26; i++) {
                    print(i);
                }
            }
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
