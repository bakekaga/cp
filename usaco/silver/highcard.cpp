// Easy greedy problem. For every card Elsie plays, Bessie can just play the smallest card
// she has that is still greater than Elsie's, which can be found with binary search. It can
// be solved without iterators and sets by just using arrays and sorting them (oops).

#include <bits/stdc++.h>

#define MAXN 50000

using namespace std;
typedef long long ll;

void fileIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

int main() {
    fileIO("highcard");

    int n = 0, count = 0;
    cin >> n;

    set<int> elsie;
    set<int> bessie;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        elsie.insert(a);
    }

    for (int i = 0; i < 2 * n; i++) {
        if (!elsie.count(i + 1)) {
            bessie.insert(i + 1);
        }
    }

    for (auto it = elsie.begin(); it != elsie.end(); it++) {
        if (bessie.lower_bound(*it) != bessie.end()) {
            count++;
            bessie.erase(*bessie.lower_bound(*it));
        }
    }

    cout << count << '\n';
    return 0;
}