#include <bits/stdc++.h>

#define mp make_pair
#define MAXN 1005
#define pb push_back
#define sz(x) int(x.size())
 
using namespace std;
 
void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n, k, res;
int ps[MAXN][MAXN];

int main() {
	setIO("paintbarn");
    int x1,x2,y1,y2;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1++;x2++;y1++;y2++;
        ps[x1][y1]++;
        ps[x2][y2]++;
        ps[x1][y2]--;
        ps[x2][y1]--;
    }

    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            ps[i][j] += ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];
    		if (ps[i][j] == k) res++;
        }
    }

    cout << res << '\n';
}