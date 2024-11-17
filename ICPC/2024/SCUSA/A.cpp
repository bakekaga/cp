#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    string s;
    int cnt = 1;
    for (int d = 1; d <= r; d++) {
        cin >> s;
        int diff = c - sz(s);
        for (int i = 0; i < diff / 2; i++) {
            cout << '.';
        }
        if (cnt % 2 == 0 && diff % 2) {
            cout << '.';
        }
        cout << s;
        if (cnt % 2 && diff % 2) {
            cout << '.';
        }
        if (diff % 2) {
            cnt++;
        }
        for (int i = 0; i < diff / 2; i++) {
            cout << '.';
        }
        cout << '\n';
    }

    return 0;
}