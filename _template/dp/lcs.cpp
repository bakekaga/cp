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

string lcs(string &text1, string &text2) {
	int m = text1.size();
	int n = text2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (text1[i] == text2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	string ret;
	while (n && m) {
		if (text1[n - 1] == text2[m - 1]) {
			ret += text1[n - 1] + ret;
			n--;
			m--;
		}
		else if (dp[n - 1][m] > dp[n][m - 1]) {
			n--;
		}
		else {
			m--;
		}
	}
	return ret;
}

int editDistance(string &text1, string &text2, int c_i, int c_d, int c_s) {
	int m = text1.size();
	int n = text2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i <= m; i++)
		dp[i][0] = i * c_d;
	for (int i = 0; i <= n; i++)
		dp[0][i] = i * c_i;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j] + c_i, min(dp[i][j - 1] + c_d, dp[i - 1][j - 1] + c_s));
		}
	}
	return dp[m][n];
}

int lcsEditDistance(string &text1, string &text2) {
	return (text1.size() + text2.size() - editDistance(text1, text2, 1, 1, INF)) / 2;
}