// Easy prefix sums problem. Keep track of prefix sums of H, G, J and just 
// output the differences between the prefix sums at the index of the end of
// the interval and the prefix sums at the index of the start of the interval.

#include <iostream>
#include <algorithm>
#include <array>

#define MAXN 100001
#define endl '\n'

using namespace std;
typedef long long ll;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int psumsH[MAXN];
int psumsG[MAXN];
int psumsJ[MAXN];

int main() {
    fileIO("bcount");
    // ios::sync_with_stdio;
    // cin.tie(0);

    int n, q;
    cin >> n >> q;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            psumsH[i + 1] = psumsH[i] + 1;
            psumsG[i + 1] = psumsG[i];
            psumsJ[i + 1] = psumsJ[i];
        }
        else if (x == 2) {
            psumsH[i + 1] = psumsH[i];
            psumsG[i + 1] = psumsG[i] + 1;
            psumsJ[i + 1] = psumsJ[i];
        }
        else if (x == 3) {
            psumsH[i + 1] = psumsH[i];
            psumsG[i + 1] = psumsG[i];
            psumsJ[i + 1] = psumsJ[i] + 1;
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << psumsH[y] - psumsH[x - 1] << " " << psumsG[y] - psumsG[x - 1] << " " << psumsJ[y] - psumsJ[x - 1] << '\n';
    }
}