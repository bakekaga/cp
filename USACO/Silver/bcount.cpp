// Easy prefix sums problem. Keep track of prefix sums of H, G, J and just 
// output the differences between the prefix sums at the index of the end of
// the interval and the prefix sums at the index of the start of the interval.

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int psums[MAXN][3];

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x; x--;
        for (int j = 0; j < 3; j++) {
            psums[i + 1][j] = psums[i][j];
            if (j == x) psums[i + 1][j]++;
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        for (int j = 0; j < 2; j++) cout << psums[y][j] - psums[x - 1][j] << ' ';
        cout << psums[y][2] - psums[x - 1][2] << '\n';
    }
}