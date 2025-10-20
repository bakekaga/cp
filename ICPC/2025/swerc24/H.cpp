#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<string, int> freq;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		freq[x]++;
	}
	string out;
	for (auto& [key, val] : freq) {
		if (val > freq[out]) {
			out = key;
		}
	}
	cout << out << '\n';
	return 0;
}