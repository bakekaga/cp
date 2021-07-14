// 2D prefix sums solution
#include <bits/stdc++.h>
#define MAXN 1005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

int n, k;
ll psums[MAXN][MAXN];

int main() {
    setIO("paintbarn");
    cin >> n >> k;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        psums[x1][y1]++;
        psums[x1][y2]--;
        psums[x2][y1]--;
        psums[x2][y2]++;
    }
    ll ret = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i) psums[i][j]+= psums[i - 1][j];
            if (j) psums[i][j]+= psums[i][j - 1];
            if (i && j) psums[i][j]-= psums[i - 1][j - 1];
            if (psums[i][j] == k) ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}
