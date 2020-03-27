// Easy prefix sums problem. Keep track of prefix sums of H, G, J and just 
// output the differences between the prefix sums at the index of the end of
// the interval and the prefix sums at the index of the start of the interval.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define MAXN 100000
#define endl '\n'

using namespace std;
typedef long long ll;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int psumsH[MAXN+1];
int psumsG[MAXN+1];
int psumsJ[MAXN+1];

int main() {
    fileIO("bcount");
    // ios::sync_with_stdio;
    // cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a == 1) {
            psumsH[i] = psumsH[i-1]+1;
            psumsG[i] = psumsG[i-1];
            psumsJ[i] = psumsJ[i-1];
        }
        if (a == 2) {
            psumsH[i] = psumsH[i-1];
            psumsG[i] = psumsG[i-1]+1;
            psumsJ[i] = psumsJ[i-1];
        }
        if (a == 3) {
            psumsH[i] = psumsH[i-1];
            psumsG[i] = psumsG[i-1];
            psumsJ[i] = psumsJ[i-1]+1;
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << psumsH[b] - psumsH[a-1] << " " << psumsG[b] - psumsG[a-1] << " " << psumsJ[b] - psumsJ[a-1] << endl;
    }
}