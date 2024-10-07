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

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".txt").c_str(), "r", stdin);
        freopen((prob + "out.txt").c_str(), "w", stdout);
    }
}

int main() {
    setIO("B");
	int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        ll p;
		cin >> p;
		vector<map<int, map<int, int>>> dp(1, map<int, map<int, int>>());
		dp[0][0][1] = 0;
		bool cont = true, found = false;
		while (cont && !found) {
			map<int, map<int, int>> nxt;
			for (int d = 1; d <= 41; d++) {
				for (auto &[sum, prodMap] : dp[sz(dp) - 1]) {
					for (auto &[prod, val] : prodMap) {
						if (p % (prod * d) == 0 && sum + d <= 41) {
							nxt[sum + d][prod * d] = d;
							cont = false;
						}
					}
				}
			}
			cont = !cont;
			dp.pb(nxt);
			for (auto &[sum, prodMap] : dp[sz(dp) - 1]) {
				for (auto &[prod, val] : prodMap) {
					if (p == prod && sum == 41) found = true;
				}
			}
		}
		cout << "Case #" << tt << ": ";
		if (found) {
			int curSum = 41, curProd = p;
			cout << sz(dp) - 1 << ' ';
			for (int i = sz(dp) - 1; i > 0; i--) {
				int cur = dp[i][curSum][curProd];
				cout << cur << ' ';
				curSum -= cur;
				curProd /= cur;
			}
			cout << '\n';
		}
		if (!cont) cout << -1 << '\n';
    }
}