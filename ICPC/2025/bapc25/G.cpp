#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	int k;
	cin >> k;
	set<string> e;
	for (int i = 0; i < k; i++) {
		string w;
		cin >> w;
		e.insert(w);
	}
	vector<int> dp(n + 1, 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		string cur = "";
		for (int j = 0; j <= 9; j++) {
			if (i + j == n) {
				break;
			}
			cur += s[i + j];
			if (j >= 5 and e.count(cur)) {
				dp[i] |= dp[i + j + 1];
			}
		}
	}
	cout << (dp[0] ? "yes" : "no") << "\n";
	return 0;
}
