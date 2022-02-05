#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	string s;
	int best = 0, count = 1;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) best = max(count++, best);
		else count = 1;
	}
	cout << best + 1 << '\n';
	return 0;
}