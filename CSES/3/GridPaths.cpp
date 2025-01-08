#include <bits/stdc++.h>
#define MAXN 1005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

struct mi {
    int v;
    mi() : mi(0) {}
    mi(int _v) : v(_v) {
        if (v >= MOD) v -= MOD;
        if (v < 0) v += MOD;
    }
    mi(ll _v) : mi((int)(_v % MOD)) {}

    mi operator+(const mi &m2) const { return mi(v + m2.v); }
    mi operator-(const mi &m2) const { return mi(v - m2.v); }
    mi operator*(const mi &m2) const { return mi((ll) v * m2.v); }
    mi operator/(const mi &m2) const { return mi((ll) v * m2.inv().v); }
    mi &operator+=(const mi &m2) { return *this = *this + m2; }
    mi &operator-=(const mi &m2) { return *this = *this - m2; }
    mi &operator*=(const mi &m2) { return *this = *this * m2; }
    mi &operator/=(const mi &m2) { return *this = *this / m2; }

    mi pow(ll e) const {
        mi res = 1;
        mi n = *this;
        while (e > 0) {
            if (e & 1) res *= n;
            n *= n;
            e >>= 1;
        }
        return res;
    }
    
    mi inv() const {
        return pow(MOD - 2);
    }
};

mi dp[MAXN][MAXN];
bool grid[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
	cin >> n;
	string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == '*') grid[i][j] = true;
        }
    }
	dp[0][0] = mi(!grid[0][0]);
	for (int i = 1; i < n; i++) {
		dp[0][i] = dp[0][i - 1].v != 0;
		if (grid[0][i]) dp[0][i].v = 0;
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0].v != 0;
		if (grid[i][0]) dp[i][0].v = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (grid[i][j]) dp[i][j].v = 0;
		}
	}
	cout << dp[n - 1][n - 1].v << '\n';
}