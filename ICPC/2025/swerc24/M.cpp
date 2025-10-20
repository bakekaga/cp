#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'O') {
			cout << ".-.-";
		} else {
			cout << ".-";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}