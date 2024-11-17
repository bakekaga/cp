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

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<array<int, 2>> vertices = {{0, 0}, {0, 2024}, {2024, 0}, {2024, 2024}};

    int cnt = 0;
    if (find(vertices.begin(), vertices.end(), array<int, 2>{x1, y1}) != vertices.end()) {
        cnt++;
    }
    if (find(vertices.begin(), vertices.end(), array<int, 2>{x2, y2}) != vertices.end()) {
        cnt++;
    }

    if (cnt == 2) {
        cout << 0 << '\n';
    }
    else if (cnt == 1) {
        cout << 1 << '\n';
    }
    else {
        cout << 2 << '\n';
    }
    return 0;
}