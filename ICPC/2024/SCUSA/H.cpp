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

    int a, b;
    cin >> a >> b;

    int out = 0;
    if (a < b) {
        out = a * 10;
    }
    else {
        out = b * 10;
        a -= b;
        out += a / 3 * 10;
        if (a % 3 == 1) out++;
        else if (a % 3 == 2) out += 3;
    }
    cout << out << '\n';

    return 0;
}